//leetcode
int eleInArr(int* arr,int n, int ele){
    for(int i= 0; i<n;i++){
        if(arr[i] == ele){
            return 1;
        }
    }
    return 0;
}

int numComponents(struct ListNode* head, int* nums, int numsSize) {
    struct ListNode * temp = head;
    int maxLen = 0;
    int tempMax = 0;
    while(temp!=NULL){
        if(eleInArr(nums,numsSize,temp->val)){
            tempMax++;
            if(tempMax==1){
                maxLen++;
            }
        } else{
           tempMax=0; 
        }
        temp=temp->next;
    }
    return maxLen;
}