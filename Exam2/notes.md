Bit-Vector (BV) Set / Bitmap 

Key ideas: Represent set of integers in range [0..m-1] as bits in array; set-membership O(1); memory-efficient for dense sets.

Operations & complexities: add/remove/test O(1); union/intersection via bitwise ops O(m/word_size).



Hashing — Open (Linear/Quadratic/Double) & Closed (Chaining)

Key ideas: Map keys to buckets via hash function; handle collisions by open addressing (probing) or chaining (external lists). Load factor α = n/m.

Complexities (expected):
- Search/Insert/Delete (chaining): O(1 + α) average
- Open addressing: depends on probing & α, performance degrades as α→1


Priority Queue & Heap Sort (Binary Heap)

Binary heap as complete binary tree in array; min-heap or max-heap; heapify, sift-up, sift-down.

Operations & complexities: insert O(log n), extract-max/min O(log n), build-heap O(n), heapsort O(n log n) in-place.


Binary Tree — BFS, DFS, and Typical Operations

Trees with nodes, left/right; BFS uses queue (level-order), DFS uses stack/recursion (pre/in/post-order).

Operations & complexities: traverse O(n); insert/delete depends on tree type (BST vs generic binary tree).
