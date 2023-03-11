#pragma once


template <typename T>
struct Initializable {
    T value;
    bool is_initialized = false;

    void initialize(T value) {
        this->is_initialized = true;
        this->value = value;
    }

    T get() {
        return this->value;
    }
};