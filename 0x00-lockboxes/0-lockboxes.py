#!/usr/bin/python3
""" lockboxes 0  """


def inspectboxes(box, boxes, keys):
    """ Inspect every box recursively
        box: list
        keys: set
    """
    # if type(box) != list:
    #     return
    for i in box:
        if i not in keys and i < len(boxes):
            keys.add(i)
            print(keys)
            inspectboxes(boxes[i], boxes, keys)


def canUnlockAll(boxes):
    """ Find if all the boxes can be opened
        boxes: list of list
    """
    # if boxes == [] or boxes is None or type(boxes[0]) != list:
    #     return False
    keys = set([0])
    unlocked = [0]

    while unlocked != []:
        box = unlocked.pop()
        for key in boxes[box]:
            if key not in keys:
                keys.add(key)
                unlocked.append(key)

    if len(keys) == len(boxes):
        return True
    else:
        return False
    # inspectboxes(boxes[0], boxes, keys)

    # for i in range(len(boxes)):
    #     if i not in keys:
    #         return False
    # return True
