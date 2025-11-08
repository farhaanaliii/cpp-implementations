#include <string>
#include <bitset>

inline std::string base2_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::string bin_str;
	bin_str.reserve(text.length() * 8);
	
	for(size_t i = 0; i < text.length(); i++){
        bin_str += std::bitset<8>((unsigned char)text[i]).to_string();
	}
	
	return bin_str;
}

inline std::string base2_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    std::string decoded_str;
    decoded_str.reserve(encoded.length() / 8);
    
    for(size_t i = 0; i < encoded.length(); i += 8){
        if(i + 8 > encoded.length()) break;
        std::string s8 = encoded.substr(i, 8);
        decoded_str += (char)stoi(s8, nullptr, 2);
    }

    return decoded_str;
}
