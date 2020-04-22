# Lockboxes Problem

You have **n** number of locked boxes in front of you. Each box is numbered sequentially from **0** to **n - 1** and each box may contain keys to the other boxes.

The function determines if all the boxes can be opened. If all boxes can be opened returns **True**, otherwise **False**.

* Boxes is a list of lists
* A key with the same number as a box opens that box.

#### Example:

```python
>>> boxes = [[1], [2], [3], [4], []]
>>> print(canUnlockAll(boxes))
True
>>> boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
>>> print(canUnlockAll(boxes))
True
>>> boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
>>> print(canUnlockAll(boxes))
False
```