Algorithm
Forward Traversal (displayForward)
1.Start
2.Set pointer current = head
3.If current == NULL, display "Directory is empty" and exit.
4.While current != NULL:
   Print employee details stored in current.
   Set current = current->next.
5.End
Backward Traversal (displayBackward)
1.Start
2.Set pointer current = tail
3.If current == NULL, display "Directory is empty" and exit.
4.While current != NULL:
Print employee details stored in current.
Set current = current->prev.
5.End

Flowchart:
                          +---------+---------+
                                    |
                                    v
                          +-------------------+
                          |  current = head   |
                          +---------+---------+
                                    |
                                    v
                           /-----------------\
                          /  current == NULL? \
                          \                   /
                           \-----------------/
                              /           \
                       YES   /             \   NO
                            v               v
                +-------------------+   +----------------------+
                | Print "Empty List"|   | Print current Node   |
                +---------+---------+   | Employee details     |
                          |             +----------+-----------+
                          |                        |
                          |                        v
                          |             +----------------------+
                          |             | current = current->next
                          |             +----------+-----------+
                          |                        |
                          |                        v
                          |             +----------------------+
                          |             |    Loop to Check     |
                          |             |  current == NULL     |
                          |             +----------+-----------+
                          |                        |
                          +------------+-----------+
                                       |
                                       v
                             +-------------------+
                             |        END        |
                             +-------------------+

  output:
  --- EMPLOYEE DIRECTORY (FORWARD) ---
ID: 101  | Name: Alice Smith     | Dept: Engineering | Salary: $95000.00
ID: 102  | Name: Bob Jones       | Dept: Marketing   | Salary: $72000.00
ID: 103  | Name: Carol Vance     | Dept: HR          | Salary: $68000.00

--- EMPLOYEE DIRECTORY (BACKWARD) ---
ID: 103  | Name: Carol Vance     | Dept: HR          | Salary: $68000.00
ID: 102  | Name: Bob Jones       | Dept: Marketing   | Salary: $72000.00
ID: 101  | Name: Alice Smith     | Dept: Engineering | Salary: $95000.00
