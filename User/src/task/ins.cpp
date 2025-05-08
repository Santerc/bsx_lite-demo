//
// Created by 59794 on 2024/12/12.
//
#include <cmsis_os.h>

#include "task/ins.h"
#include "dwt_api.h"
#include "periph/bmi088.h"

#include <vector>
#include <cmath>

extern "C"{
#include "bsxlite_interface.h"
#include "arm_math.h"
}

bsp::SPI imu_spi(hspi1);
bsp::GPIO accel_cs(*GPIOC, GPIO_PIN_15);
bsp::GPIO gyro_cs(*GPIOC, GPIO_PIN_14);
imu::Bmi088 ins(imu_spi, accel_cs, gyro_cs);

bsxlite_instance_t ins_instance;
vector_3d_t accel_data = {0, 0, 0};
vector_3d_t gyro_data = {0, 0, 0};

bsxlite_out_t bsx_out;
insData_t ins_data;

uint32_t last_tick = 0;

uint32_t prev_time = 0;


static void INS_Task(void* parameter)
{
    static bool init_flag{false};
    ins_data = {
        0,0,0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0};
    if (!init_flag) {
        bsp::DWT_Init(170);
        ins.Init();
        while(ins.error_ != imu::Bmi088::Error::NO_ERROR){
            ins.Init();
        }
        init_flag  = true;
    }
    bsxlite_init(&ins_instance);
    while (true)
    {
        ins.Decode();

        accel_data = {ins.accel_data_.x, ins.accel_data_.y, ins.accel_data_.z};
        gyro_data = {ins.gyro_data_.pitch, ins.gyro_data_.row, ins.gyro_data_.yaw};


        bsxlite_do_step(&ins_instance, 1000*HAL_GetTick(), &accel_data, &gyro_data, &bsx_out);

        ins_data.space_omega_ = {
            ins.gyro_data_.yaw,
            ins.gyro_data_.pitch,
            ins.gyro_data_.row
        };
        ins_data.space_att_ = {
            bsx_out.orientation.yaw,
            bsx_out.orientation.pitch,
            bsx_out.orientation.roll
        };

        osDelay(10);
    }
}

const insData_t* GetInsData() {
    return &ins_data;
}

const float GetSpeed()
{
    const float32_t vel[2] = {ins_data.space_vel_.x, ins_data.space_vel_.y};
    float32_t mag;
    arm_rms_f32(vel, 2, &mag);
    return mag;
}

void InsTaskStart(void)
{
    xTaskCreate(INS_Task, "INSTask", 256, NULL, 7, NULL);
}

