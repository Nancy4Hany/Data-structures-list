#include "EXPRESSION_TREE.h" ; 
#include <stdexcept>
using namespace std; 



ExpressionTree::ExpressionTree(int n, ExpressionTree* left_sub, ExpressionTree* right_sub) :
	value(n), left_tree(left_sub), right_tree(right_sub) {
	// Empty constructor.
}

ExpressionTree::~ExpressionTree() {
	if (left_tree != 0 || right_tree != 0) {
		left_tree = 0; // Set the pointer to point to null.
		right_tree = 0; // Set the pointer to point to null.
	}
}

ExpressionTree* ExpressionTree::left() const {
	return left_tree; // Returns a pointer to the left subtree.
}

ExpressionTree* ExpressionTree::right() const {
	return right_tree; // Returns a pointer to the right subtree.
}

int ExpressionTree::retrieve() const {
	return value; // Return the value of the current node.
}

void ExpressionTree::clear() {
	// Delete every single node in the tree.
	if (left() != 0) {
		left()->clear();
	}
	if (right() != 0) {
		right()->clear();
	}
	delete this;
}

bool ExpressionTree::is_leaf() const {
	return (left() == 0) && (right() == 0); // If the current node has no children, then it is a leaf node.
}

int ExpressionTree::evaluate() const {
	if (is_leaf()) {
		return value; // Return the value of the current node if the current node is a leaf node.
	}
	else {
		if (value == PLUS) {
			return (left()->evaluate() + right()->evaluate()); // Do addition
		}
		else if (value == MINUS) {
			return (left()->evaluate() - right()->evaluate()); // Do subtraction
		}
		else if (value == TIMES) {
			return (left()->evaluate() * right()->evaluate()); // Do multiplication
		}
		else if (value == DIVIDE) {
			return (left()->evaluate() / ((right()->evaluate() ))); // Do division, throw exception if the denominator is zero.
		}
		else {
			return 0; // Return 0 otherwise
		}
	}
}

void ExpressionTree::in_fix(int x) const {
	char sign;
	bool open_bracket = false;

	if (is_leaf()) {
		cout << value; // If the current node is a leaf node, print the value.
	}
	else {
		// Determine the operator.
		if (value == PLUS) {
			sign = '+';
		}
		else if (value == MINUS) {
			sign = '-';
		}
		else if (value == TIMES) {
			sign = '*';
		}
		else if (value == DIVIDE) {
			sign = '/';
		}

		if (((x == TIMES || x == DIVIDE) && (value == PLUS || value == MINUS)) ||
			(x == MINUS && (right()->value == PLUS || right()->value == MINUS)) ||
			(x == DIVIDE && (right()->value == TIMES || right()->value == DIVIDE))) {
			// Parentheses must be used if:
			// 1. An addition or subtraction operation is a child of a multiplication or division operation; or
			// 2. An addition or subtraction is the right sub-operation of a subtraction; or
			// 3. A multiplication or division is the right sub-operation of a division.
			cout << '(';
			open_bracket = true;
		}

		left()->in_fix(value); // Print out the left subtree
		cout << ' ' << sign << ' '; // Print out the operator
		right()->in_fix(value); // Print out the right subtree

		if (open_bracket) {
			cout << ')'; // Close bracket
			open_bracket = false;
		}
	}
}

void ExpressionTree::reverse_polish() const {
	//If the node is a leaf node, print the node. 
	//Otherwise, print the left sub-tree, then the right sub-tree, 
	//and then print the operator (+, -, *, or /, as appropriate). 
	//Each of these should be followed by a space.

	char sign;
	if (is_leaf()) {
		cout << value; // If the node is a leaf node, print the value.
	}
	else {
		// Determine operator
		if (value == PLUS) {
			sign = '+';
		}
		else if (value == MINUS) {
			sign = '-';
		}
		else if (value == TIMES) {
			sign = '*';
		}
		else if (value == DIVIDE) {
			sign = '/';
		}

		left()->reverse_polish(); // Print out the left subtree
		cout << ' ';
		right()->reverse_polish(); // Print out the right subtree
		cout << ' ';
		cout << sign;
	}
}


