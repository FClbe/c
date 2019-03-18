
#include "pch.h"
#include<string.h>
#include <iostream>

int main()
{

	char input[100];
	char command[10];
	char key[10];
	char value[60];
	printf("Input: ");
	fgets(input, 100, stdin);
	char* input1 = input;
      char* temp = strchr(input1, ' ');//找到空格
	  if (temp != NULL) {
		  temp[0] = '\0';//替换成\0
		  strcpy_s(command, 10, input1);
		  input1 = temp + 1;
		  temp = strchr(input1, ' ');//找到空格
		  if (temp != NULL) {
			  temp[0] = '\0';//替换成\0
			  strcpy_s(key, 10, input1);
			  input1 = temp + 1;
			  strcpy_s(value, 60, input1);
			  printf("command:   %s\n", command);
			  printf("key:       %s\n", key);
			  printf("value:     %s\n", value);
		  }
		  else {
			  strcpy_s(key, 10, input1);
			  printf("command:   %s\n", command);
			  printf("key:       %s\n", key);
		  }
	  }else{
		  strcpy_s(command, 10, input1);
		  printf("command:   %s\n", command);
		  }

	  system("pause");
	//temp[0] = '\0';
	//printf("%s\n1", temp);
}

