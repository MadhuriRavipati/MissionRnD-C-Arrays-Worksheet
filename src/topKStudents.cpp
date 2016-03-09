/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
void swap(struct student *s, int i, int j) {
	struct student t;
	t = s[i];
	s[i] = s[j];
	s[j] = t;
}
void sort(struct student *s, int n){
	int i, j;
	for (i = 0; i < n; i++){
		for (j = i; j < n; j++){
			if (s[i].score < s[j].score)
				swap(s, i, j);

		}
	}
}

struct student ** topKStudents(struct student *students, int len, int K) {
	int i = 0, max = 0, x, j;
	if (students == NULL || len == 0 || K <= 0)
		return NULL;
	if (K == 1){

		for (i = 0; i < len; i++)
		{
			if (students[i].score > max){
				max = students[i].score;
				x = i;
			}
		}
		struct student **topKstudents = (struct student**)calloc(K, sizeof(struct student));
		topKstudents[0] = &students[x];
		return topKstudents;
	}
	else
	{
		struct student **topKstudents = (struct student**)calloc(K, sizeof(struct student));
		sort(students, len);
		for (j = 0; j < K; j++)
			topKstudents[j] = &students[j];
		return topKstudents;
	}
}