# VariableEliminationForBayesianNetwork

The project aims to build an inference engine for Bayesian networks based on the Variable Elimination algorithm, whose output is the a posteriori probability of each variable.

Variable Elimination is a simple exact inference algorithm used in graphical probabilistic models, such as Bayesian Networks. This algorithm exploits the distributivity of addition (marginalisation) over multiplication to decompose the problem into smaller subproblems. It has exponential execution complexity but can be efficient for low tree-width graphs.

The project implements the following specifications:
- the input is read from files in XDSL format of the SMILE library
- a Copy-On-Write semantics is used to minimise memory occupation in the case of identical structures
- the computation is parallelised using multithreading
