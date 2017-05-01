/* This source file models a simple connectionist neural network.
 * There are only two nodes as of now. 
 * Author: Kaushik Choudhary
 */

#include "simpleNeuralNet.hpp"

int main()
{
    Node A(10,2);
    Node B(20,1);
    cout<<"A's activation level = "<<A.activationLevel<<" and weight = "<<A.weight<<endl;
    cout<<"B's activation level = "<<B.activationLevel<<" and weight = "<<B.weight<<endl;
    cout<<A.activationLevel + B.activationLevel<<endl; 
    printf("Before: B's activation level = %d and weight = %d\n",B.activationLevel,B.weight);
    printf("Before: A's activation level = %d and weight = %d\n",A.activationLevel,A.weight);

    A.send(B);
    B.send(A);
    printf("After: B's activation level = %d and weight = %d\n",B.activationLevel,B.weight);
    printf("After: A's activation level = %d and weight = %d\n",A.activationLevel,A.weight);

    cout<<"A's activation level = "<<A.activationLevel<<" and weight = "<<A.weight<<endl;
    cout<<"B's activation level = "<<B.activationLevel<<" and weight = "<<B.weight<<endl;

    
    return 0;
}
