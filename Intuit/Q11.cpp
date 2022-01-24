// Represents a rectangle range where
// row indices are in [r1, r2)
// column indices are in [c1, c2)
class Range {
    int r1, r2;
    int c1, c2;

    Range(int r1, int r2, int c1, int c2) {
        this.r1 = r1;
        this.r2 = r2;
        this.c1 = c1;
        this.c2 = c2;
    }

    int size() {
        return (r2-r1) * (c2-c1);
    }

    Range topLeft() {
        return new Range(
            r1, (r1+r2)/2,
            c1, (c1+c2)/2
        );
    }

    Range topRight() {
        return new Range(
            r1, (r1+r2)/2,
            (c1+c2)/2, c2
        );
    }

    Range bottomLeft() {
        return new Range(
            (r1+r2)/2, r2,
            c1, (c1+c2)/2
        );
    }

    Range bottomRight() {
        return new Range(
            (r1+r2)/2, r2,
            (c1+c2)/2, c2
        );
    }

    public String toString() {
        return String.format("r1=%d r2=%d c1=%d c2=%d", r1, r2, c1, c2);
    }
}

// Creates Node with isLeaf and val property set
// Finds sum of the given range in grid to check for isLeaf
private Node create(int[][] grid, Range r) {
	int sum = 0;
    for (int i = r.r1; i < r.r2; ++i) {
        for (int j = r.c1; j < r.c2; ++j) {
            sum += grid[i][j];
        }
    }
    boolean isLeaf = sum == 0 || sum == r.size();
    boolean val = isLeaf && sum == r.size();
    return new Node(val, isLeaf);
}

// recursively constructs the tree with given range
private Node construct(int[][] grid, Range r) {
    Node node = create(grid, r);
    if (node.isLeaf)
        return node;

    node.topLeft = construct(grid, r.topLeft());
    node.topRight = construct(grid, r.topRight());
    node.bottomLeft = construct(grid, r.bottomLeft());
    node.bottomRight = construct(grid, r.bottomRight());
    return node;
}

public Node construct(int[][] grid) {
    return construct(grid, new Range(0, grid.length, 0, grid[0].length));
