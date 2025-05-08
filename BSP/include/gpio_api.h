//
// Created by 18759 on 2024/12/2.
//

#ifndef GPIO_H
#define GPIO_H
#ifdef __cplusplus
extern "C" {
#endif

#include "gpio.h"

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace bsp {
    class GPIO final {
    public:
        GPIO_TypeDef &handle_;
        GPIO_PinState state_;
        uint16_t pin_;
        uint32_t tick_;

        GPIO() = delete;

        explicit GPIO(GPIO_TypeDef &handle, uint16_t pin) : handle_(handle), pin_(pin), state_(GPIO_PIN_RESET),
                                                            tick_(0) {}

        void Reset();

        void Set();

        GPIO_PinState ReadPin();

        [[gnu::pure]][[maybe_unused, nodiscard]] uint32_t GetTriggerTick() const{return tick_;};
    };
}
#endif
#endif //GPIO_H
