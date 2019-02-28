include <stdio.h>
#include <stdlib.h>


typedef struct segment {
  int l, r;
  int a;
} segment;

typedef struct node_tag {
  int l, r;
  int sum;
  int suml, sumr;
  int suma;
  struct node_tag *nodel, *noder;
} node_tag;

node_tag *
build_tree(int l, int r) 
{
  int m = (l + r) / 2;
  node_tag *nodep = (node_tag*)malloc(sizeof(node_tag));
  nodep->l = l, nodep->r = r;
  nodep->sum = 0;
  nodep->suma = 0;
  nodep->suml = nodep->sumr = 0;
  if (l == r) 
    nodep->nodel = nodep->noder = NULL;
  else 
    {
      nodep->nodel = build_tree(l, m);
      nodep->noder = build_tree(m + 1, r);
    }
  return nodep;
}

int 
sum_segment(int l, int r, int a) 
{
  return (r + l) * (r - l + 1) / 2 * a;
}

void 
lazy(node_tag *nodep)
{
  node_tag * nodel = nodep->nodel;
  node_tag * noder = nodep->noder;
  int l = nodep->l;
  int r = nodep->r;
  int m = (l + r) / 2;
  if (nodep->suml == 0 && nodep->sumr == 0) 
    return;
  nodel->suma += nodep->suma;
  noder->suma += nodep->suma;
  nodel->suml += nodep->suml;
  noder->sumr += nodep->sumr;
  nodel->sumr += ((r - l + 1) * (nodep->suml + nodep->sumr) 
                  - (m - l + 1) * nodep->suml 
                  - (r - m) * nodep->suma
                  - (r - m) * nodep->sumr) / (r - l + 1);
  noder->suml += nodel->sumr + nodep->suma;
  nodel->sum += (m - l + 1) * (nodel->suml + nodel->sumr) / 2;
  noder->sum += (r - m) * (noder->suml + noder->sumr) / 2;
  nodep->suma = nodep->suml = nodep->sumr = 0;
}


void 
update(int l, int r, int a, node_tag *nodep) 
{
  if (nodep->r < l || nodep->l > r)
    return;
  if (nodep->l >= l && nodep->r <= r) 
    {
      nodep->sum  += sum_segment(nodep->l - l + 1, nodep->r - l + 1, a); 
      nodep->suma += a;
      nodep->suml += a * (nodep->l - l + 1);
      nodep->sumr += a * (nodep->r - l + 1);
      return;
    }
  lazy(nodep);
  update(l, r, a, nodep->nodel);
  update(l, r, a, nodep->noder);
  nodep->sum = nodep->nodel->sum + nodep->noder->sum;
}

int query(int l, int r, node_tag *nodep)
{
  if (nodep->r < l || nodep->l > r) 
    return 0;
  if (nodep->l >= l && nodep->r <= r)
    return nodep->sum;
  lazy(nodep); 
  return query(l, r, nodep->nodel) + query(l, r, nodep->noder);
}

int n, q;
node_tag *root;
int 
main() 
{
  int t, l, r, a;
  scanf("%d%d", &n, &q);
  root = build_tree(1, n); 
  while (q--) 
    {
      scanf("%d", &t);
      if (t == 1) 
        {
          scanf("%d%d%d", &l, &r, &a);
          update(l, r, a, root); 
        }
     else 
       {
         scanf("%d%d", &l, &r);
         printf("%d\n", query(l, r, root));
       }
    }
  return 0;
}
