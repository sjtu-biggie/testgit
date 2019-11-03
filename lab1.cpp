#include "common.h"

using namespace Minisat;

bool lab1(int states[], int n, int button[][2], int m, bool answer[])
{
    Solver solver;
    Var variables[1000];
    int i, j;
    for(i = 0; i<m; ++i)
        variables[i] = solver.newVar();

	//

    //TODO : your solution here.
    int k=0;
    int p=0;
    int state[n][2];
    for(int i=0;i<n;++i)
    {
	state[i][0]=state[i][1]=-1;
    }

    for(int i=0;i<m;++i)
    {
	k=button[i][0];
	p=button[i][1];
	if(state[k-1][0]==-1)	state[k-1][0]=i;
   	    else state[k-1][1]=i;
	if(state[p-1][0]==-1)	state[p-1][0]=i;
   	    else state[p-1][1]=i;
    }
    for(int i=0;i<n;++i){
        printf("%d\t",state[i][0]);
        printf("%d\n",state[i][1]);
    	if(states[i]==0)
	    if(state[i][1]==-1)
		{

    		    solver.addClause(mkLit(variables[state[i][0]]));
		}
		else {
		    solver.addClause(mkLit(variables[state[i][0]]),  mkLit(variables[state[i][1]]));
		    solver.addClause(~mkLit(variables[state[i][0]]), ~mkLit(variables[state[i][1]]));
		}

    	if(states[i]==1)
	    if(state[i][1]==-1)
		{
    		    solver.addClause(~mkLit(variables[state[i][0]]));
		}
		else {
		    solver.addClause(~mkLit(variables[state[i][0]]),  mkLit(variables[state[i][1]]));
		    solver.addClause(mkLit(variables[state[i][0]]), ~mkLit(variables[state[i][1]]));
		}
    }
    //solve SAT problem
    auto sat = solver.solve();
    if(sat)
    {
        for(i = 0; i < m; ++i)
            answer[i] = (solver.modelValue(variables[i]) == l_True);
        return true;
    }
    return false;
}




