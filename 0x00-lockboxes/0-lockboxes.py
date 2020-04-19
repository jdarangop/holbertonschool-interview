#!/usr/bin/python3
""" lockboxes 0  """


def inspectboxes(box, boxes, keys):
    """ Inspect every box recursively
        box: list
        keys: set
    """
    for i in box:
        if i not in keys and i < len(boxes):
            keys.add(i)
            inspectboxes(boxes[i], boxes, keys)


def canUnlockAll(boxes):
    """ Find if all the boxes can be opened
        boxes: list of list
    """
    if boxes == [] or boxes is None:
        return False
    keys = set([0])
    inspectboxes(boxes[0], boxes, keys)

    for i in range(len(boxes)):
        if i not in keys:
            return False
    return True
