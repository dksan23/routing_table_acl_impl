#include <stdint.h>

typedef enum bit_type_
{
    ZERO,
    ONE,
    DONT_CARE,
    BIT_TYPE_MAX
}bit_type_t;

typedef struct bitmap_
{
    uint32_t bits;
}bitmap_t;

typedef struct mtrie_node_
{
    bitmap_t prefix;
    bitmap_t wildcard;
    uint16_t prefix_len;
    struct mtrie_node_ *parent;
    struct mtries_node_ *child[BIT_TYPE_MAX];
    void *data;
}mtrie_node_t;

void bitmap_set_at(bitmap_t *bitmap, uint8_t index)
{
    if(!bitmap)
    {
        return;
    }
    if(index >= 32)
    
        return;
    }
    bitmap->bits = (bitmap->bits | (1 << index));
}