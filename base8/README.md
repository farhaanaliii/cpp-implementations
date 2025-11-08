# Base8 (Octal) Encoding

Octal encoding uses digits 0-7 to represent data in base 8 format.

## Usage

```cpp
#include "base8.h"
#include <iostream>

int main(){
    std::string text = "Hi";
    
    std::string encoded = base8_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: 22151
    
    std::string decoded = base8_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hi
    
    return 0;
}
```

## Features
- Uses digits 0-7
- 3-bit chunks
- Common in UNIX file permissions
- O(1) character lookup
