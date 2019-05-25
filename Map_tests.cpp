#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sem4_lab2(1)/Map.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(MethodsTests)
{
public:
	Map<int, int> * testTree;

	TEST_METHOD_INITIALIZE(SetUp)
	{
		testTree = new Map<int, int>;
	}

	TEST_METHOD_CLEANUP(CleanUp)
	{
		delete testTree;
	}

	TEST_METHOD(insert_case1) // head node case
	{
		testTree->insert(5, 5);

		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->get_value() == 5 && current->leaf() == false);
	}
	TEST_METHOD(insert_case2) // parent is BLACK
	{
		testTree->insert(5, 5);
		testTree->insert(6, 6);
		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();

		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == RED && current->get_value()==6 && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->get_value() == 5 && current->leaf() == false);

	}
	TEST_METHOD(insert_case3) // parent and uncle are RED
	{
		testTree->insert(5, 5);
		testTree->insert(6, 6);
		testTree->insert(4, 4);
		testTree->insert(3, 3);

		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 3 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 4 && current->get_color() == BLACK && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 6 && current->get_color() == BLACK && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 5 && current->get_color() == BLACK && current->leaf() == false);
	}

	TEST_METHOD(insert_case4_rotateRight) //parent is RED, uncle is BLACK, current is left, parent is right
	{
		testTree->insert(5, 5);
		testTree->insert(7, 7);
		testTree->insert(6, 6);

		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 5 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 7 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 6 && current->get_color() == BLACK && current->leaf() == false);
	}

	TEST_METHOD(insert_case4_rotateLeft) //parent is RED, uncle is BLACK, current is right, parent is left
	{
		testTree->insert(5, 5);
		testTree->insert(3, 3);
		testTree->insert(4, 4);

		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 3 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 5 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 4 && current->get_color() == BLACK && current->leaf() == false);
	}

	TEST_METHOD(insert_case5_rotateLeft) //parent is RED, uncle is BLACK, current is right, parent is right
	{
		testTree->insert(5, 5);
		testTree->insert(6, 6);
		testTree->insert(7, 7);

		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 5 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 7 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 6 && current->get_color() == BLACK && current->leaf() == false);
	}

	TEST_METHOD(insert_case5_rotateRight) //parent is RED, uncle is BLACK, current is left, parent is left
	{
		testTree->insert(5, 5);
		testTree->insert(4, 4);
		testTree->insert(3, 3);

		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 3 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 5 && current->get_color() == RED && current->leaf() == false);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_value() == 4 && current->get_color() == BLACK && current->leaf() == false);
	}



	TEST_METHOD(find)
	{
		testTree->insert(5, 6);
		testTree->insert(6, 7);
		testTree->insert(7, 8);
		testTree->insert(8, 9);
		testTree->insert(9, 10);

		Assert::IsTrue(testTree->find(5)->get_value() == 6 &&
			testTree->find(6)->get_value() == 7 &&
			testTree->find(7)->get_value() == 8 &&
			testTree->find(8)->get_value() == 9 &&
			testTree->find(9)->get_value() == 10);
	}

	TEST_METHOD(find_wrongKey)
	{
		testTree->insert(5, 6);
		testTree->insert(6, 7);
		testTree->insert(7, 8);
		testTree->insert(8, 9);
		testTree->insert(9, 10);

		Assert::IsTrue(testTree->find(1) == nullptr);
	}

	TEST_METHOD(insert_Exception)
	{
		testTree->insert(5, 5);
		try
		{
			testTree->insert(5, 5);
		}
		catch (domain_error message)
		{
			Assert::AreEqual("There are nodes with this key", message.what());
		}
	}

	TEST_METHOD(clear)
	{
		testTree->insert(5, 6);
		testTree->insert(6, 7);
		testTree->insert(7, 8);
		testTree->insert(8, 9);
		testTree->insert(9, 10);

		testTree->clear();

		Assert::IsTrue(testTree->is_empty() == true);
	}
	TEST_METHOD(get_keys)
	{
		testTree->insert(5, 5);
		testTree->insert(6, 6);
		testTree->insert(7, 7);
		ListClass<int> * list = testTree->get_keys();

		Assert::IsTrue(list->at(0) == 5 &&
			list->at(1) == 7 &&
			list->at(2) == 6);
	}
	TEST_METHOD(get_values)
	{
		testTree->insert(5, 5);
		testTree->insert(6, 6);
		testTree->insert(7, 7);
		ListClass<int> * list = testTree->get_values();
		int list_size = list->get_size();

		Assert::IsTrue(list->at(0) == 5 &&
			list->at(1) == 7 &&
			list->at(2) == 6);
	}
	
	TEST_METHOD(delete_case1) // child is new head
	{
		testTree->insert(5, 5);
		testTree->remove(5);


		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
	}
	TEST_METHOD(delete_case2_and_3) // child's brother is red and then new brother is black and new brother's children are black
	{
		testTree->insert(5, 5);
		testTree->insert(6, 6);
		testTree->insert(4, 4);
		testTree->insert(3, 3);

		testTree->remove(4);
		testTree->remove(3);
		testTree->remove(5);


		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->get_value() == 6 && current->leaf() == false);
	}
	TEST_METHOD(delete_case4) // brother and his chindren are black but parent is red
	{
		testTree->insert(5, 5);
		testTree->insert(6, 6);
		testTree->insert(4, 4);
		testTree->insert(7, 7);
		testTree->insert(8, 8);
		testTree->insert(9, 9);
		testTree->insert(3, 3);

		testTree->remove(4);
		testTree->remove(7);
		testTree->remove(6);
		testTree->remove(8);

		testTree->remove(3);

		testTree->remove(5);


		Dft_iterator<int, int> * dft_iterator = new Dft_iterator<int, int>(testTree);
		TreeNode<int, int> * current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->leaf() == true);
		current = dft_iterator->next();
		Assert::IsTrue(current->get_color() == BLACK && current->get_value() == 9 && current->leaf() == false);
	}
	

};
