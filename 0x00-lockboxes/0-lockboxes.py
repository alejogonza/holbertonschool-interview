#!/usr/bin/python3
"""boxopen"""


def canUnlockAll(boxes):

    opened_boxes = [0]
    i = 0

    while i < len(opened_boxes):

        if boxes[opened_boxes[i]] == [] or \
                (set(boxes[opened_boxes[i]]).issubset(opened_boxes)):
            pass
        else:
            for b in boxes[opened_boxes[i]]:

                if b < len(boxes) and b not in opened_boxes:
                    opened_boxes.append(b)
                else:
                    continue
        i += 1

    return True if len(opened_boxes) == len(boxes) else False
