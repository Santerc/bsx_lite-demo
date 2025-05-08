//
// Created by 18759 on 2024/11/30.
//

#ifndef CALLBACK_H
#define CALLBACK_H
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include "functional"
#include "array"

template<uint8_t kMaxCallbacks, typename ReturnType, typename ...Args>
class Callback {
public:
    static const uint8_t kMaxCallbacks_ = kMaxCallbacks;
    using CallbackType = std::function<ReturnType(Args...)>;

    std::array<CallbackType, kMaxCallbacks_> callbacks_{nullptr};
    uint8_t callback_count_{0};

    void AddCallback(CallbackType p_callback) {
        if (callback_count_ < kMaxCallbacks_) {
            callbacks_.at(callback_count_++) = p_callback;
        }
    }

    void Call(Args ...args) {
        for (auto callback: callbacks_) {
            if (callback == nullptr) break;
            callback(args...);
        }
    }
};

#endif
#endif //CALLBACK_H
