
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
     Node *temp=head,*prev=NULL;
     int tm=M,tn=N;
     while(temp!=NULL)
     {
      if(tm!=0)
      {
       tm--;
       prev=temp;
       temp=temp->next;
      }
      else
      {
       if(tn==0)
       {
        tm=M;
        continue;
       }
       tn--;
       prev->next=temp->next;
       temp=temp->next;
       if(tn==0)
       {
        tm=M;
        tn=N;
       } 
      }
     }
    }
};
