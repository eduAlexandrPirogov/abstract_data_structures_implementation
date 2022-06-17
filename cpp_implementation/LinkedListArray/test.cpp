#include "pch.h"
#include "../LinkedListArray/LinkedListArray.h"
#include "../LinkedListArray/LinkedListArray.cpp"

TEST(LinkedListArray, CreatingArrayList) {
	LinkedListArray<int> ar{};
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_NIL);
	EXPECT_EQ(ar.size(), 0);
}

TEST(LinkedListArray, PushBack) {
	LinkedListArray<int> ar{};
	ar.push_back(5);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_OK);
	EXPECT_EQ(ar.size(), 1);
	EXPECT_EQ(ar.at(0), 5);

	ar.push_back(15);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_OK);
	EXPECT_EQ(ar.size(), 2);
	EXPECT_EQ(ar.at(1), 15);
}

TEST(LinkedListArray, InsertByIndex) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 7; i++)
	{
		ar.push_back(i);
		EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_OK);
	}
	EXPECT_EQ(ar.size(), 7);

	ar.insert_at(20, 5);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_OK);
	EXPECT_EQ(ar.at(5), 20);
	EXPECT_EQ(ar.at(4), 4);
	EXPECT_EQ(ar.at(6), 5);
}
TEST(LinkedListArray, InsertByIndexAtStart) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 8; i++)
		ar.push_back(i);

	EXPECT_EQ(ar.size(), 8);

	ar.insert_at(20, 0);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_OK);
	EXPECT_EQ(ar.at(0), 20);
	EXPECT_EQ(ar.at(1), 0);
	EXPECT_EQ(ar.at(2), 1);
}
TEST(LinkedListArray, InsertByIndexEnd) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 9; i++)
		ar.push_back(i);

	ar.insert_at(20, 9);
	EXPECT_EQ(ar.at(9), 20);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_OK);
}

TEST(LinkedListArray, InsertInFullList) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	ar.insert_at(20, 5);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_LIST_IS_FULL);
}

TEST(LinkedListArray, InsertInInvalidIndex) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	ar.insert_at(20, -5);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_INVALID_INDEX);

	ar.insert_at(20, 5000);
	EXPECT_EQ(ar.get_insert_status(), ar.INSERT_STATUS_INVALID_INDEX);
}
TEST(LinkedListArray, EraseByIndex) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	ar.erase(0);
	EXPECT_EQ(ar.size(), 9);
	EXPECT_EQ(ar.at(0), 1);
	EXPECT_EQ(ar.at(1), 2);
	EXPECT_EQ(ar.get_erase_status(), ar.ERASE_STATUS_OK);
}

TEST(LinkedListArray, EraseByEnd) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	ar.erase(9);
	EXPECT_EQ(ar.size(), 9);
	EXPECT_EQ(ar.at(8), 8);
	EXPECT_EQ(ar.get_erase_status(), ar.ERASE_STATUS_OK);
}

TEST(LinkedListArray, EraseInvalidIndex) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	ar.erase(-1);
	EXPECT_EQ(ar.get_erase_status(), ar.ERASE_STATUS_INVALID_INDEX);

	ar.erase(999);
	EXPECT_EQ(ar.get_erase_status(), ar.ERASE_STATUS_INVALID_INDEX);
}

TEST(LinkedListArray, TestOperatorBrackets) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	long long tmp = ar[5];
	long long tmp2 = 5;
	ASSERT_EQ(tmp, tmp2);

}

TEST(LinkedListArray, TestCopyConstructor) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	LinkedListArray<int> ar2{ ar };
	ASSERT_FALSE(&ar == &ar2);
}

TEST(LinkedListArray, TestMoveConstructor) {
	LinkedListArray<int> ar{};
	for (int i = 0; i < 10; i++)
		ar.push_back(i);

	LinkedListArray<int> ar2{ std::move(ar) };
	assert(ar.size() == 0);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}