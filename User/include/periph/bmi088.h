//
// Created by 18759 on 2024/12/2.
//

#ifndef BMI088_H
#define BMI088_H
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include "bmi088_reg.h"
#include "spi_api.h"
#include "gpio_api.h"



namespace imu {

    constexpr float kGravity = 9.81f;
    constexpr float OFFLINE_TIME=0.3f;

    enum class State: uint8_t{
        STATE_NULL = 0,
        STATE_CONNECTED = 1,
        STATE_LOST = 2,
        STATE_ERROR = 3,
        STATE_PENDING = 4
    };

    typedef struct{
        float x;
        float y;
        float z;
    }AccelData;
    typedef struct{
        float yaw;
        float pitch;
        float row;
    }SpeedData;


    class Bmi088 {
    public:

        State state_;
        bsp::SPI &spi_;
        bsp::GPIO &gpio_accel_;
        bsp::GPIO &gpio_gyro_;
        AccelData accel_data_{.x = 0.0f, .y = 0.0f, .z = 0.0f};
        SpeedData gyro_data_{.yaw = 0.0f, .pitch = 0.0f, .row = 0.0f};

        float gyro_offset_[3];
        float accel_offset_[3];
        float gNorm_;
        float accel_scale_;

        uint8_t caliOffset{1};
        float ACCEL_SEN{reg::ACCEL_6G_SEN};
        float GYRO_SEN{reg::GYRO_2000_SEN};
        uint8_t calibrate{0};
        float temperature{0.0f};

        float update_dt{0.0f};
        uint32_t last_update_tick{0};

        using Error = reg::Error;
        Error error_{Error::NO_ERROR};


        Bmi088(bsp::SPI &spi, bsp::GPIO &gpio_accel, bsp::GPIO &gpio_gyro)
        : spi_(spi), gpio_accel_(gpio_accel), gpio_gyro_(gpio_gyro){
            state_ = State::STATE_NULL;
            gNorm_ = 9.8F;
            accel_data_ = {0.0f, 0.0f, 0.0f};
            gyro_data_ = {0.0f, 0.0f, 0.0f};
        }

        void Init();
        void Reset();
        Error InitAccel();
        Error InitGyro();

        Error TestAccel();
        Error TestGyro();
        void Decode();



    private:

        // void WriteSingleReg(bsp::GPIO &gpio,uint8_t reg, uint8_t data);
        //
        //
        // void ReadSingleReg(bsp::GPIO &gpio,uint8_t reg, uint8_t data);
        //
        //
        // void ReadMultiReg(bsp::GPIO &gpio,uint8_t reg, uint8_t *data, uint16_t data_len);

        void WriteAccelSingleReg(uint8_t reg, uint8_t data);
        uint8_t ReadAccelSingleReg(uint8_t reg);
        void ReadAccelMultiReg(uint8_t reg, uint8_t *data, uint16_t data_len);
        void WriteGyroSingleReg(uint8_t reg, uint8_t data);
        uint8_t ReadGyroSingleReg(uint8_t reg);
        void ReadGyroMultiReg(uint8_t reg, uint8_t *data, uint16_t data_len);

        void SetOffset();
        void GetOffset();

    };
}

#endif
#endif //BMI088_H
