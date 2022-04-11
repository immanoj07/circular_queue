#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct queue
{

    int *arr;
    int size;
    int front;
    int rear;
};
bool is_empty(struct queue *q)
{

    return (q->front == q->rear);
}
bool is_full(struct queue *q)
{

    return (((q->rear + 1) % (q->size)) == q->front);
}
int push(struct queue *q, int x)
{

    if (!is_full(q))
    {
        q->arr[(++q->rear) % q->size] = x;
        return 0;
    }
    printf("Queue is FULL\n");
    return -1;
}
int pop(struct queue *q)
{

    if (!is_empty(q))
    {
        ++(q->front);
        return q->arr[q->front];
    }
    printf("Queue is EMPTY\n");
    return -1;
}
void display(struct queue *q)
{
    if (is_empty(q))
    {
        printf("EMPTY QUEUE\n");
        return;
    }
    int i = q->front, end = q->rear;
    while (i != end)
    {
        printf("%d ->", q->arr[(i + 1)%(q->size)]);
        i++;
    }
    printf("\n");
}

int elements_in_queue(struct queue *q)
{
    if (q->rear >= q->front)
    {
        return q->rear - q->front;
    }
    else
    {
        return (q->size - (q->front - q->rear));
    }
}
bool init_q(struct queue *q, int size)
{

    q->arr = (int *)malloc(sizeof(int) * size);
    if (q->arr == NULL)
    {
        return false;
    }
    q->front = q->rear = 0;
    q->size = size;
    return true;
}
int main()
{
    struct queue *q = NULL;
    q = (struct queue *)malloc(sizeof(struct queue));
    if (q == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    int size = 0;

    printf("Enter size of the queue\n");
    scanf("%d", &size);
    if (init_q(q, size))
    {
        printf("Queue initialized successfully\n");
    }
    else
    {
        printf("Queue Init Failed\n");
        return 1;
    }

    int choice, ele;
    while (1)
    {
        printf("\nEnter choice\n"
               "1. Enqueue "
               "2. Dequeue "
               "3. Display "
               "4. No. of Elements "
               "5. Free Queue\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert\n ");
            scanf("%d", &ele);
            if (push(q, ele) == 0)
            {
                printf("Enque successful\n");
                display(q);
            }
            else
            {
                printf("Failure\n");
            }
            break;
        case 2:

            if ((ele = pop(q)) != -1)
            {
                printf("Dequeued %d\n", ele);
                display(q);
            }
            else
            {
                printf("Failure\n");
            }
            break;
        case 3:
            display(q);
            break;
        case 4:
            display(q);
            printf("%d Elements in Queue", elements_in_queue(q));
            break;
        case 5:
            free(q->arr);
            free(q);
            printf("SUCCESS!");
            break;
        default:
            return 0;
        }
    }
}