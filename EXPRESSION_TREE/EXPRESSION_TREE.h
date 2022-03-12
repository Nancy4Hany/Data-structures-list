
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H
#include <iostream>
using namespace std;
class ExpressionTree
{
	private:
		int value;
		ExpressionTree* left_tree;
		ExpressionTree* right_tree;

	public:
		//Constructors
		ExpressionTree(int = 0, ExpressionTree* = 0, ExpressionTree* = 0);
		//This constructor takes three arguments: an integer and two pointers which point to ExpressionTree objects. (O(1))
		~ExpressionTree();

		static const int PLUS = 0;
		static const int MINUS = 1;
		static const int TIMES = 2;
		static const int DIVIDE = 3;

		// Accessors

		bool is_leaf() const;
		int evaluate() const;
		//If the node is a leaf node, return the value. Otherwise, the node represents an operator, in which case, you perform the operation on the evaluated sub trees. If a division is being performed and the denominator is zero, a division_by_zero exception is thrown. (O(n))
		void in_fix(int x) const;
		void reverse_polish() const;
		ExpressionTree* left() const;
		ExpressionTree* right() const;
		int retrieve() const;
		void clear();
		// Mutators
		void add(int);
		void subtract(int);
		void subtracted_from(int);
		void times(int);
		void divided_by(int);
		void divides(int);
};

#endif

