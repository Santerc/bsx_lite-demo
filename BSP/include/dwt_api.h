//
// Created by 18759 on 2024/12/2.
//

#ifndef DWT_API_H
#define DWT_API_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace bsp {
    typedef struct {
        uint32_t s;
        uint32_t ms;
        uint16_t us;
        uint32_t ms_tick;
    } DWT_TimeTypeDef;

    typedef struct {
        DWT_TimeTypeDef SysTime;

        uint32_t CPU_FREQ_Hz, CPU_FREQ_Hz_ms, CPU_FREQ_Hz_us;
        uint32_t CYCCNT_RountCount;
        uint32_t CYCCNT_LAST;
        uint64_t CYCCNT64;
    } DWT_DataTypeDef;

    DWT_DataTypeDef *DWT_GetDWTDataPtr(void);

    void DWT_Init(uint32_t CPU_Freq_mHz);

    float DWT_GetDeltaT(uint32_t *cnt_last);

    float DWT_GetDeltaTWithoutUpdate(uint32_t *cnt_last);

    float DWT_GetTimeline_s(void);

    float DWT_GetTimeline_ms(void);

    uint64_t DWT_GetTimeline_us(void);

    void DWT_Delay(float Delay);

    void DWT_Delayms(float Delay);

    void DWT_Delayus(float Delay);

    void DWT_SysTimeUpdate(void);

    void DWT_CNT_Update(void);

}

#endif
#endif //DWT_API_H
