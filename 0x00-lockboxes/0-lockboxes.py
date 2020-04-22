#!/usr/bin/python3
"""Verify if all the boxes can be opened"""


# ------------------------------RECURSIVE WAY --------------------------------
# def open_box(box, opened, boxes):
#     """ Opens the input box, and opens the other boxes
#     with the keys founded.
#
#     Args:
#         box (list): the keys founded in the box.
#         opened (list): the list with the boxes that were opened.
#         boxes (list): the whole list of boxes/keys.
#
#     Returns:
#         list: the list of boxes that were opened.
#     """
#     # Finish if the box has no keys or all the keys are from opened boxes.
#     if box == [] or (set(box).issubset(opened)):
#         return opened
#     else:
#         for b in box:
#             if b < len(boxes) and b not in opened:
#                 opened.append(b)
#                 # Open the box, but save a temporal list to allow
#                 # the iteration.
#                 temp_opened = open_box(boxes[b], opened, boxes)
#                 # Update the list and iterate
#                 opened = temp_opened
#             else:
#                 continue
#         return opened
#
#
# def canUnlockAll(boxes):
#     """Says if all boxes can be opened by opening first the
#     box #0.
#
#     Args:
#         boxes (list): information of all boxes/keys.
#
#     Returns:
#         bool: True if all boxes could be opened. Otherwise False.
#     """
#     if len(boxes) < 1:
#         return
#     boxes_opened = [0]
#     opened = open_box(boxes[0], boxes_opened, boxes)
#     if len(opened) == len(boxes):
#         return True
#     else:
#         return False

# ------------------------------ITERATIVE WAY --------------------------------
def canUnlockAll(boxes):
    """Says if all boxes can be opened by opening first the box #0.

    Args:
        boxes (list): list of lists with information of all boxes/keys.

    Returns:
        bool: True if all boxes could be opened. Otherwise False.
    """
    opened_boxes = [0]
    i = 0

    while i < len(opened_boxes):
        # Pass if empty or all keys of opened boxes
        if boxes[opened_boxes[i]] == [] or \
                (set(boxes[opened_boxes[i]]).issubset(opened_boxes)):
            pass
        else:
            for b in boxes[opened_boxes[i]]:
                # Append the box if not wrong number or opened before
                if b < len(boxes) and b not in opened_boxes:
                    opened_boxes.append(b)
                else:
                    continue
        i += 1

    return True if len(opened_boxes) == len(boxes) else False
