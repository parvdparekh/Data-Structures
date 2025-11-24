bool isPalindrome(struct ListNode* head) {
    struct ListNode *ptr=head;
    int arr[100000];
    int i=0;
    while(ptr!=NULL)
    {
        arr[i]=ptr->val;
        ptr=ptr->next;
        i+=1;
    }
    ptr=head;
    for(int j=i-1;j>=0;j--)
    {
        if(ptr->val!=arr[j])
            return false;
        ptr=ptr->next;
    }
    return true;
}
