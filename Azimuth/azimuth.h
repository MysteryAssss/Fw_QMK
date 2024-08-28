// Copyright 2024 (@LQT)

#pragma once

#include "quantum.h"

typedef struct hc165_key {
    int8_t driver;
    int8_t channel;
} __attribute__((packed)) hc165_key;