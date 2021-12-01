/*
    We have: logical address, frame/page size (16 bytes, 2^4 bits), !RAM size (8 frames, or 16*8 = 128 bytes)
    We need to calculate
        1. Offset (logical address mod frame size)
        2. Logical page number (logical address div frame size)
        3. Physical page number (compare with page table Page Number --> Frame Number)
        4. Physical Address (Physical page number * page size + offset)
*/

