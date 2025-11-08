# cpp-implementations
A repo with C++ code for algorithms, encodings, and other cool stuff!

## Table of Contents
- [Introduction](#introduction)
- [Algorithms](#algorithms)
- [Encodings](#encodings)
- [Other Cool Stuff](#other-cool-stuff)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction
This repository contains various C++ implementations of algorithms, encoding techniques, and other interesting projects. It is designed to help you learn and understand different C++ concepts and techniques.

## Algorithms
In this section, you will find implementations of various algorithms, including sorting, searching, and more.

## Encodings
This section includes different base encoding techniques implemented in C++. All implementations are optimized with O(1) lookup tables, memory reservation, and const references.

### Available Encodings

| Name | Alphabet Size | Characters | Use Case |
|------|--------------|------------|----------|
| **Base2** | 2 | 0-1 | Raw binary representation |
| **Base8** | 8 | 0-7 | Octal, UNIX permissions |
| **Base10** | 10 | 0-9 | Human-readable decimal |
| **Base16** | 16 | 0-9, A-F | Hexadecimal, memory dumps |
| **Base32** | 32 | A-Z, 2-7 | Compact, case-insensitive, TOTP codes |
| **Base36** | 36 | 0-9, A-Z | Short IDs, URLs |
| **Base58** | 58 | 1-9, A-Z, a-z (no 0, O, I, l) | Bitcoin addresses, avoids lookalikes |
| **Base62** | 62 | 0-9, A-Z, a-z | Short URLs, databases |
| **Base64** | 64 | A-Z, a-z, 0-9, +, / | Standard encoding, web, binary to text |
| **Base85** | 85 | ASCII printable | Adobe, PostScript, compression-friendly |

Each encoding is in its own directory with a header file and README containing usage examples.

## Other Cool Stuff
Here you will find other interesting C++ projects and implementations that don't fit into the above categories.

## Installation
To use the code in this repository, clone it to your local machine using:
```sh
git clone https://github.com/farhaanaliii/cpp-implementations.git
```

## Usage
Navigate to the directory of the specific implementation you want to use and follow the instructions in the README file within that directory.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.