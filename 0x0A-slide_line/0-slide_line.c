#include "slide_line.h"


/**
 * slide_left - slide the line to the left.
 * @line: line to apply the slide.
 * @size: size of the array.
 *
 * Return: Void.
 */
void slide_left(int *line, size_t size)
{
	int counter, i, j;

		counter = 0;
		for (i = 0; i < (int)size; i++)
		{
			if (i == (int)size - 1)
			{
				line[counter] = line[i];
				counter++;
			}
			if (line[i] != 0)
			{
				for (j = i + 1; j < (int)size; j++)
				{
					if (line[j] == 0)
						continue;
					if (line[i] == line[j])
					{
						line[counter] = line[i] * 2;
						counter++;
						i = j;
						break;
					}
					if (line[i] != line[j])
					{
						line[counter] = line[i];
						counter++;
						break;
					}
				}
			}
		}
		for (i = counter; i < (int)size; i++)
		{
			line[i] = 0;
		}
}


/**
 * slide_right - slide the line to the right.
 * @line: line to apply the slide.
 * @size: size of the array.
 *
 * Return: Void.
 */
void slide_right(int *line, size_t size)
{
	int counter, i, j;

		counter = size - 1;
		for (i = size - 1; i >= 0; i--)
		{
			if (i == 0)
			{
				line[counter] = line[i];
				counter--;
			}
			if (line[i] != 0)
			{
				for (j = i - 1; j >= 0; j--)
				{
					if (line[j] == 0)
						continue;
					if (line[i] == line[j])
					{
						line[counter] = line[i] * 2;
						counter--;
						i = j;
						break;
					}
					if (line[i] != line[j])
					{
						line[counter] = line[i];
						counter--;
						break;
					}
				}
			}
		}
		for (i = counter; i >= 0; i--)
		{
			line[i] = 0;
		}
}


/**
 * slide_line - slide the line.
 * @line: line to apply the slide.
 * @size: size of the array.
 * @direction: direction to slide.
 *
 * Return: Void.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);
	if (direction == 1)
	{
		slide_left(line, size);
		return (1);
	}
	else if (direction == 0)
	{
		slide_right(line, size);
		return (1);
	}
	else
	{
		return (0);
	}
}
