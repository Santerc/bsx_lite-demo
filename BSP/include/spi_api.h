//
// Created by 18759 on 2024/12/2.
//

#ifndef SPI_API_H
#define CHASSIS_SPI_API_H
#ifdef __cplusplus
extern "C" {
#endif

#include "spi.h"
//#include "dma.h"

//void SPI_Init(SPI_HandleTypeDef *hspi);
//void SPI_Send(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t len, uint32_t timeout);
//void SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t len, uint32_t timeout);
//void SPI_SendDMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t len);
//void SPI_ReceiveDMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t len);
//void SPI_Swap(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t len, uint32_t timeout);
//void SPI_SwapDMA(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t len);
//uint8_t SPI_SwapAbyte(SPI_HandleTypeDef *hspi, uint8_t txdata);
//void ReadMultiReg(SPI_HandleTypeDef *hspi, uint8_t *rx_data, uint8_t len);
//void SPI_ErrorHandler(uint32_t ret);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus

#include "callback.h"

namespace bsp {
    class SPI final {
    public:
        SPI_HandleTypeDef &handle_;
        SPI() = delete;
        explicit SPI(SPI_HandleTypeDef &handle): handle_(handle){};
        uint8_t SwapAByte(uint8_t tx_data);
        void ReadMultiReg(uint8_t *rx_data, uint16_t len);
    };
}

#endif
#endif //CHASSIS_SPI_API_H
