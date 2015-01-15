#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "expr_assert.h"
#include "febo.h"

void test_fibo_should_return_1_for_1(){
	int n =1;
	int *array;

	assertEqual(fibo(n,&array),1);
	free(array);
}

void test_fibo_should_return_0_for_minus_1(){
	int n =-1;
	int *array;

	assertEqual(fibo(n,&array),0);
	free(array);
}

void test_fibo_should_return__1for_Zeroth_position_of_array(){
	int n =3;
	int *array;

	assertEqual(fibo(n,&array),1);
	assertEqual(array[0], 0);
	assertEqual(array[1], 1);
	free(array);
}

void test_fibo_should_return_5_for_4th_position_of_array(){
	int n = 6;
	int *array;

	assertEqual(fibo(n,&array),1);
	assertEqual(array[0], 0);
	assertEqual(array[1], 1);
	assertEqual(array[3], 2);
	assertEqual(array[4], 3);
	assertEqual(array[5], 5);
	free(array);
}

void test_concat_should_return__concated_array_for_array1_and_array2(){

	int array1[]={1,2,3};
	int array2[]={4,5,6};

	int *resultArray;
	assertEqual(concat(array1,3,array2,3,&resultArray),1);

	assertEqual(resultArray[0],1);
	assertEqual(resultArray[1],2);
	assertEqual(resultArray[2],3);
	assertEqual(resultArray[3],4);
	assertEqual(resultArray[4],5);
	assertEqual(resultArray[5],6);
	free(resultArray);

}

void test_concat_should_return_a_new_concated_array_for_array1_and_array2(){
	int array1[6]={5,6,13,23,46,35};
	int array2[6]={34,23,35,24,34,3};
	int *resultArray;
	int i;

	assertEqual(concat(array1,6,array2,6,&resultArray),1);

	assertEqual(resultArray[0],5);
	assertEqual(resultArray[1],6);
	assertEqual(resultArray[2],13);
	assertEqual(resultArray[3],23);
	assertEqual(resultArray[4],46);
	assertEqual(resultArray[5],35);
	
	assertEqual(resultArray[6],34);
	assertEqual(resultArray[7],23);
	assertEqual(resultArray[8],35);
	assertEqual(resultArray[9],24);
	assertEqual(resultArray[10],34);
	free(resultArray);

}

void test_filter_remove_all_the_element_less_than_thresold_value(){
int array[] = {4,3,7,34,2,52};
int *resultArray;
int thresold = 5;

assertEqual(filter(array,6,thresold,&resultArray),1);

assertEqual(resultArray[0],7);
assertEqual(resultArray[1],34);
assertEqual(resultArray[2],52);
free(resultArray);
	
}

void test_reverse_reverse_all_the_element_of_array(){
int array[] = {4,3,7,34,2,52};
int *resultArray;
int thresold = 5;

assertEqual(reverse(array,6,&resultArray),1);

assertEqual(resultArray[0],52);
assertEqual(resultArray[1],2);
assertEqual(resultArray[2],34);
assertEqual(resultArray[3],7);
assertEqual(resultArray[4],3);
assertEqual(resultArray[5],4);
free(resultArray);

}

void test_slice_give_the_new_array_with_slice_the_array (){
	int array[] = {4,5,2,12,34,5,6};
	int len_of_array=7, start_index = 2,end_index=5;
	int *result_array;

	assertEqual(slice(array,len_of_array,start_index,end_index,&result_array), 1);

	assertEqual(result_array[0],2);
	assertEqual(result_array[1],12);
	assertEqual(result_array[2],34);
	free(result_array);
};

void test_slice_give_0_if_last_index_is_grater_than_length_of_array (){
	int array[] = {4,5,2,12,34,5,6};
	int len_of_array=7, start_index = 6,end_index=8;
	int *result_array;

	assertEqual(slice(array,len_of_array,start_index,end_index,&result_array), 0);
	free(result_array);
};

void test_primeNunmer_give_the_prime_number_between_a_range(){
	int *array;
	int start=1,end=10;
	assertEqual(primeNumber(start,end,&array),4);
	assertEqual(primeNumber(start,100,&array),25);
	assertEqual(primeNumber(start,1000,&array),168);
	free(array);
};

void test_my_strcmp_compare_two_string(){
	assertEqual(my_strcmp("helllo","hafjweh"),strcmp("helllo","hafjweh"));
};

void test_my_strcmp_compare_two_string_with(){

	assertEqual(my_strcmp("helllol","helpMe"),strcmp("helllol","helpMe"));
}

int addBy2(int num1){
	return (num1+2);
};

void test_forEach_apply_function_on_each_element_of_array(){
	int (*functionPtr)(int),length=6,i;
	int array[]={2,4,56,-5,7,89,4};
	int result[]={4,6,58,-3,9,91,6};

	functionPtr = &addBy2;

	forEach(array,length,functionPtr);
	for(i=0;i<length;i++){
		assertEqual(array[i],result[i]);
	};
};

int upperCase(char letter){
	if(letter >=65 && letter <=90){
		return letter+32;
	};
	return 1;
};

void test_char_forEach_perform_operation_on_each_element_of_array(){
	int (*functionPtr)(char),length=6,i;
	char array[]={'H','E','L','L','O','\0'};

	functionPtr = &upperCase;

	char_forEach(array,length,functionPtr);
};

int isEven(int number){
	return ((number%2)==0)?1:0;
};

void test_filter_perform_filter_on_each_element_of_array_and_give_new_array(){
	int (*functionPtr)(int);
	int length=9,i;
	int array[]={-5,2,4,56,-5,7,89,0,9};
	int expected[]={2,4,56,0};
	int *result;

	functionPtr = &isEven;
	
	assertEqual(myFilter (array, length, functionPtr, &result) ,1);

	for(i=0;i<4;i++){
		assertEqual(result[i], expected[i]);
	};
	free(result);
};

int lessThan5(float num){
	return((num <5))?1:0;
};
void test_float_filter_perform_filter_on_each_element_of_array_and_give_new_array(){
	int (*functionPtr)(float);
	int length=9,i;
	float array[]={-5.3,2.5,4.6,56.7,5.4,3.23};
	float expected[]={-5.3,2.5,4.6,3.25};
	float *result;

	functionPtr = &lessThan5;

	assertEqual(floatFilter (array, length, functionPtr, &result) ,1);

	for(i=0;i<4;i++){
		assertEqual(result[i], expected[i]);
	};
	free(result);
};
 