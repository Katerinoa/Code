if (p1->next->data > maxValue)
        {
            deleteNextNode(p1);
            p1 = p1->next;
            continue;
        }