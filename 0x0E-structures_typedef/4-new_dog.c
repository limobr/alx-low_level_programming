#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string
 * Return: pointer to newly allocated space in memory
 */

char *_strdup(char *str)
{
	int length, i;
	char *arr;

	if (str == NULL)
	{
		return (NULL);
	}

	length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}

	arr = (char *) malloc(length * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		arr[i] = str[i];
	}
	arr[i] = '\0';

	return (arr);
}

/**
 * new_dog - creates a new dog
 * @name: brayo's name
 * @age: brayo's age
 * @owner: brayo's owner
 * Return: new_dog (dog_t)
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *brayo;
	char *brayo_name, *brayo_owner;

	brayo = malloc(sizeof(dog_t));
	if (brayo == NULL)
		return (NULL);

	brayo_name = _strdup(name);
	if (brayo_name == NULL)
	{
		free(brayo);
		return (NULL);
	}

	brayo_owner = _strdup(owner);
	if (brayo_owner == NULL)
	{
		free(brayo_name);
		free(brayo);
		return (NULL);
	}
	brayo->name = brayo_name;
	brayo->age = age;
	brayo->owner = brayo_owner;
	return (brayo);
}
