#include "pch.h"
#include "..\Library\Hex.h"

TEST(HexConstructor, DefaultConstructor) {
	lab3::Hex a;
	char outHex[3] , zeros[3] = "+0", outform_sm[5], outform_1[5], outform_2[5], zeros_1[5]="0000";
	char* tmp_1 = outHex, *tmp_2=outform_sm, *tmp_3 = outform_1, *tmp_4 = outform_2;
	a.getHex(tmp_1);
	a.get_form_sm(tmp_2);
	a.get_form_1(tmp_3);
	a.get_form_2(tmp_4);
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(outHex[i], zeros[i]);
	}
	for (int i = 0; i < 4; i++) {
		EXPECT_EQ(outform_sm[i], zeros_1[i]);
	}
	for (int i = 0; i < 4; i++) {
		EXPECT_EQ(outform_1[i], zeros_1[i]);
	}
	for (int i = 0; i < 4; i++) {
		EXPECT_EQ(outform_2[i], zeros_1[i]);
	}
}
TEST(HexConstructor, InitialiserConstructor_positive_char) {
	char tmp[] = "A";
	char* tmp_x = tmp;
	lab3::Hex a(tmp_x);
	char outHex[3], test_hex[3] = "+A", outform_sm[6], outform_1[6], outform_2[6], test_form_sm[6] = "01010", test_form_1[6] = "01010", test_form_2[6] = "01010" ;
	char* tmp_1 = outHex, * tmp_2 = outform_sm, * tmp_3 = outform_1, * tmp_4 = outform_2;
	a.getHex(tmp_1);
	a.get_form_sm(tmp_2);
	a.get_form_1(tmp_3);
	a.get_form_2(tmp_4);
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(outHex[i], test_hex[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_sm[i], test_form_sm[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_1[i], test_form_1[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_2[i], test_form_2[i]);
	}
}
TEST(HexConstructor, InitialiserConstructor_negative_char) {
	char tmp[] = "-A";
	char* tmp_x = tmp;
	lab3::Hex a(tmp_x);
	char outHex[3], test_hex[3] = "-A", outform_sm[6], outform_1[6], outform_2[6], test_form_sm[6] = "11010", test_form_1[6] = "10101", test_form_2[6] = "10110";
	char* tmp_1 = outHex, * tmp_2 = outform_sm, * tmp_3 = outform_1, * tmp_4 = outform_2;
	a.getHex(tmp_1);
	a.get_form_sm(tmp_2);
	a.get_form_1(tmp_3);
	a.get_form_2(tmp_4);
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(outHex[i], test_hex[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_sm[i], test_form_sm[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_1[i], test_form_1[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_2[i], test_form_2[i]);
	}
}
TEST(HexConstructor, InitialiserConstructor_integer_positive) {
	lab3::Hex a(1);
	char outHex[3], test_hex[3] = "+1", outform_sm[6], outform_1[6], outform_2[6], test_form_sm[6] = "00001", test_form_1[6] = "00001", test_form_2[6] = "00001";
	char* tmp_1 = outHex, * tmp_2 = outform_sm, * tmp_3 = outform_1, * tmp_4 = outform_2;
	a.getHex(tmp_1);
	a.get_form_sm(tmp_2);
	a.get_form_1(tmp_3);
	a.get_form_2(tmp_4);
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(outHex[i], test_hex[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_sm[i], test_form_sm[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_1[i], test_form_1[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_2[i], test_form_2[i]);
	}
}
TEST(HexConstructor, InitialiserConstructor_integer_negative) {
	lab3::Hex a(-1);
	char outHex[3], test_hex[3] = "-1", outform_sm[6], outform_1[6], outform_2[6], test_form_sm[6] = "10001", test_form_1[6] = "11110", test_form_2[6] = "11111";
	char* tmp_1 = outHex, * tmp_2 = outform_sm, * tmp_3 = outform_1, * tmp_4 = outform_2;
	a.getHex(tmp_1);
	a.get_form_sm(tmp_2);
	a.get_form_1(tmp_3);
	a.get_form_2(tmp_4);
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(outHex[i], test_hex[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_sm[i], test_form_sm[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_1[i], test_form_1[i]);
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(outform_2[i], test_form_2[i]);
	}
}
TEST(HexConstructor, InitialiserConstructor_exceptions_char_invalid_characters) {
	char tmp_k[] = "TTTTTTTTTTTTTTTTTTTTTTTTTT";
	char* tmp_y = tmp_k;
	try {
		ASSERT_ANY_THROW(lab3::Hex a(tmp_y));
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
TEST(HexConstructor, InitialiserConstructor_exceptions_int_overload_positive) {
	try {
		ASSERT_ANY_THROW(lab3::Hex a(2147483648));
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
TEST(HexConstructor, InitialiserConstructor_exceptions_int_overload_negative) {
	try {
		ASSERT_ANY_THROW(lab3::Hex a(-2147483648));
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
TEST(HexMethod, Shifts) {
	char test_1[] = "AABBCC", test_2[] = "AABBCC";
	char* test_1_ptr = test_1, * test_2_ptr = test_2;
	lab3::Hex a(test_1_ptr), b(test_2_ptr);
	a.shift_left(2);
	b.shift_right(2);
	char outTest_1[] = "+BBCC00", outTest_2[] = "+00AABB", outHex_1[8], outHex_2[8];
	char *tmp_1 = outHex_1, *tmp_2 = outHex_2;
	a.getHex(tmp_1);
	b.getHex(tmp_2);
	for (int i = 0; i < 7; i++) {
		EXPECT_EQ(outTest_1[i], outHex_1[i]);
		EXPECT_EQ(outTest_2[i], outHex_2[i]);
	}
}
TEST(HexMethod, Add_and_Subtract) {
	char test_1[] = "A", test_2[] = "2";
	char* test_1_ptr = test_1, * test_2_ptr = test_2;
	lab3::Hex a(test_1_ptr), b(test_2_ptr), c(25), d(test_1_ptr);

	c=a.add(b);
	d=a.subtract(b);
	char outTest_1[] = "+C", outTest_2[] = "+8", outHex_1[12], outHex_2[12];
	char* tmp_1 = outHex_1, * tmp_2 = outHex_2;
	c.getHex(tmp_1);
	d.getHex(tmp_2);
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(outTest_1[i], outHex_1[i]);
	}
}
TEST(HexMethod, Add_and_Subtract_exceptions) {
	char test_1[] = "AA", test_2[] = "AA", test_3[] = "-AA";
	char* test_1_ptr = test_1, * test_2_ptr = test_2, * test_3_ptr = test_3;
	lab3::Hex a(test_1_ptr), b(test_2_ptr), c(25), d(test_1_ptr), k(test_3_ptr);

	try {
		EXPECT_ANY_THROW(c = a.add(b));
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		EXPECT_ANY_THROW(d = k.subtract(b));
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
TEST(HexMethod, Compare) {
	char test_1[] = "AABBCC", test_2[] = "AABBCC";
	char* test_1_ptr = test_1, * test_2_ptr = test_2;
	lab3::Hex a(test_1_ptr), b(test_2_ptr);
	int k = 0;
	k = a.comp(b);
	EXPECT_EQ(3, k);
}
TEST(HexMethod, Is_Even) {
	char test_1[] = "AABBCC";
	char* test_1_ptr = test_1;
	lab3::Hex a(test_1_ptr);
	int k = 0;
	k = a.is_even();
	EXPECT_EQ(1, k);
}
TEST(HexMethod, Shifts_operator_overloads) {
	char test_1[] = "AABBCC", test_2[] = "AABBCC";
	char* test_1_ptr = test_1, * test_2_ptr = test_2;
	lab3::Hex a(test_1_ptr), b(test_2_ptr);
	a <<= 2;
	b >>= 2;
	char outTest_1[] = "+BBCC00", outTest_2[] = "+00AABB", outHex_1[8], outHex_2[8];
	char* tmp_1 = outHex_1, * tmp_2 = outHex_2;
	a.getHex(tmp_1);
	b.getHex(tmp_2);
	for (int i = 0; i < 7; i++) {
		EXPECT_EQ(outTest_1[i], outHex_1[i]);
		EXPECT_EQ(outTest_2[i], outHex_2[i]);
	}
}
TEST(HexMethod, Add_and_Subtract_operators) {
	char test_1[] = "A", test_2[] = "2";
	char* test_1_ptr = test_1, * test_2_ptr = test_2;
	lab3::Hex a(test_1_ptr), b(test_2_ptr), c(25), d(test_1_ptr);

	c = a+b;
	d = a-b;
	char outTest_1[] = "+C", outTest_2[] = "+8", outHex_1[12], outHex_2[12];
	char* tmp_1 = outHex_1, * tmp_2 = outHex_2;
	c.getHex(tmp_1);
	d.getHex(tmp_2);
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(outTest_1[i], outHex_1[i]);
	}
}
TEST(HexMethod, Add_and_Subtract_operators_exceptions) {
	char test_1[] = "AA", test_2[] = "AA", test_3[]="-AA";
	char* test_1_ptr = test_1, * test_2_ptr = test_2, *test_3_ptr=test_3;
	lab3::Hex a(test_1_ptr), b(test_2_ptr), c(25), d(test_1_ptr), e(test_3_ptr);

	try {
		EXPECT_ANY_THROW(c = a+b);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	try {
		EXPECT_ANY_THROW(d = e-b);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}











int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}