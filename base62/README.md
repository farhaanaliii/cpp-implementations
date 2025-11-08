# Base62 Encoding

Base62 encoding uses all alphanumeric characters (0-9, A-Z, a-z) for compact representation.

## Usage

```cpp
#include "base62.h"
#include <iostream>

int main(){
    std::string text = "Hi";
    
    std::string encoded = base62_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: 1C 1N
    
    std::string decoded = base62_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hi
    
    return 0;
}
```

## Features
- Uses 0-9, A-Z, a-z characters (62 total)
- Case-sensitive
- Space-separated values
- Common for short URLs and database keys
- Compact alphanumeric representation
