#!/usr/bin/python3
""" Island Perimeter """


def recurtion(grid, i, j, lista):
    """ performe the recurtion.
        Args:
            grid: (list of list)
            i: (int) row.
            j: (int) column.
            lista: (list) cointaining the tuples.
        Return:
            (int) perimeter.
    """
    if grid[i][j] == 1:
        if (i, j) not in lista:
            lista.append((i, j))
            return (recurtion(grid, i - 1, j, lista) +
                    recurtion(grid, i + 1, j, lista) +
                    recurtion(grid, i, j - 1, lista) +
                    recurtion(grid, i, j + 1, lista))
        else:
            return 0
    else:
        return 1


def island_perimeter(grid):
    """ returns the perimeter of the island
        described in grid.
        Args:
            grid: (list of list)
        Returns:
            (int) the perimeter of the island.
    """
    if grid is None or len(grid) == 0 or len(grid[0]) == 0:
        return 0

    total = 0
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                total += 4
                if grid[row - 1][col] == 1:
                    total -= 2
                if grid[row][col - 1] == 1:
                    total -= 2
                # return recurtion(grid, row, col, lista)

    return total
