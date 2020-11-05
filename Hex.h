#ifndef _HEX_H_
#define _HEX_H_

#include <iostream>

namespace lab3 {
	class Hex {
	private:
		static const int SZ = 10;
		int len;
		char* hex=nullptr;
		char *form_sm=nullptr;
		char *form_1=nullptr;
		char *form_2=nullptr;
		int set_forms();
		int set_hex(char *hex_value);
		int set_forms_backwards();
	public:
		//constructors
		Hex();
		Hex(char *hex_value);
		Hex(int hex_value);
		Hex(const Hex&);
		Hex(Hex&&) noexcept;
		//destructor
		~Hex() {
			if (hex != nullptr)
				delete[] hex;
			if (form_sm != nullptr)
				delete[] form_sm;
			if (form_1 != nullptr)
				delete[] form_1;
			if (form_2 != nullptr)
				delete[] form_2;
		}
		//copy and displace operators
		Hex& operator =(const Hex&);
		Hex& operator =(Hex&&) noexcept;
		//setters
		Hex& input(std::istream&);
		friend std::istream&  operator >>(std::istream& s, Hex& st);

		Hex& shift_left(int n);
		Hex& operator <<= (int);

		Hex& shift_right(int n, int condition=0);
		Hex& operator >>= (int);


		//getters
		void getHex(char *) const;
		void get_form_sm(char*) const;
		void get_form_1(char*) const;
		void get_form_2(char*) const;
	
		std::ostream & print(std::ostream&) const;
		friend std::ostream& operator <<(std::ostream& s, Hex& st);

		Hex& add(const Hex &b) const;
		Hex& operator +(Hex) const;

		Hex& subtract(Hex b) const;
		Hex& operator -(Hex) const;

		int comp(Hex b) const;
		int is_even() const;
	};
	char int_to_hex(int value);
	int hex_to_int(char value);
	int hex_to_binary(char hex_value);
	char binary_to_hex(int binary_value);
}

#endif