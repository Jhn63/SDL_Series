#pragma once

typedef struct vector_2f {
    float x;
    float y;

    bool operator==(const vector_2f& other) const {
        return (x == other.x) and (y == other.y);
    }

    bool operator!=(const vector_2f& other) const {
        return (x != other.x) and (y != other.y);
    }

}vector_2f;
