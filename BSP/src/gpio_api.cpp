//
// Created by 18759 on 2024/12/2.
//
#include "gpio_api.h"

void bsp::GPIO::Reset() {
    HAL_GPIO_WritePin(&handle_, pin_, GPIO_PIN_RESET);
    ReadPin();
}

void bsp::GPIO::Set() {
    HAL_GPIO_WritePin(&handle_, pin_, GPIO_PIN_SET);
    ReadPin();
}

GPIO_PinState bsp::GPIO::ReadPin() {
    tick_ = HAL_GetTick();
    state_ = HAL_GPIO_ReadPin(&handle_, pin_);
    return state_;
}
