#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_dog - free the brayos
 * @d: brayo
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
