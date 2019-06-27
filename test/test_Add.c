#include "unity.h"
#include <stdio.h>
#include "mock_Add.h"

//fake function add:
int fake_add(int v1, int v2, int callNumber){
  printf("hello\n");
  if(callNumber == 0)       //ex1
    return 0;
  else if(callNumber == 1)  //ex2
    return 45;
  
  return -1;				//ex3
}

int fake_minus(int v1, int v2, int callNumber){
  if(callNumber == 0)       //ex1
    return 1000;
  else if(callNumber == 1)  //ex2
    return 2000;
  //else
	return -1;				//ex3
}

void setUp(void)
{
 add_StubWithCallback(fake_add); // when call add please call fake_add
 minus_StubWithCallback(fake_minus);
}
void tearDown(void)
{
}

//test add function
void test_Add_given_2_6_expect_8(void){
  
/* fake test not affect the input order & value.  
 * test will pass with the correct return value.
 * which is 0 & 45.
*/
  TEST_ASSERT_EQUAL(0, add(2,8));	//ex1
  TEST_ASSERT_EQUAL(45, add(9,12));	// ex2
  TEST_ASSERT_EQUAL(-1, add(9,12));	// ex3
}

void test_Add_given_3_6_expect_9_sencondTime(void){
	TEST_ASSERT_EQUAL(0, add(2,8));		//ex1
	TEST_ASSERT_EQUAL(45, add(9,12));	// ex2
	TEST_ASSERT_EQUAL(-1, add(9,12));	// ex3	
	TEST_ASSERT_EQUAL(-1, add(9,13));	// ex3	
	TEST_ASSERT_EQUAL(-1, add(9,14));	// ex3	
}

//fake minus function
void test_minus_given_2_6_expect_1000_1stTimeCall_2000_2ndTimeCall_minus1_3rdTimeCall(void){
  TEST_ASSERT_EQUAL(1000, minus(2,8));	//ex1
  TEST_ASSERT_EQUAL(2000, minus(9,12));	// ex2
  TEST_ASSERT_EQUAL(-1, minus(9,12));		// ex3
}
