#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

int storeClock;

string toTime(int time) {
  int hours = (time / 60) + 8;
  int minutes = time % 60;
  string mCorrection = "";
  if (minutes < 10) mCorrection = "0";
  string timeCode = "AM";
  if (hours > 24) {
    hours -= 24;
  } else if (hours > 12) {
    hours -= 12;
    timeCode = "PM";
  }
  string result =
      to_string(hours) + ":" + mCorrection + to_string(minutes) + timeCode;
  return result;
}

class Customer {
 public:
  int inTime;
  int outTime;
  int waitTime;
  int orderTime;
  Customer *next;

  Customer() {
    inTime = storeClock;
    outTime = 0;
    waitTime = 0;
    orderTime = rand() % 6 + 1;
    next = NULL;
  }
};

class Queue {
 public:
  Customer *head;

  Queue() { head = NULL; }

  void enqueue() {
    Customer *temp = new Customer();
    if (head == NULL) {
      head = temp;
    } else {
      Customer *another;
      another = head;
      while (another->next != NULL) {
        another = another->next;
      }
      another->next = temp;
      temp->next = NULL;
    }
  }
  void dequeue() {
    if (head != NULL) {
      Customer *temp;
      temp = head;
      head = head->next;
      delete temp;
    }
  }

  int queueSize() {
    Customer *temp;
    temp = head;
    int length = 1;
    if (head == NULL) {
      return 0;
    } else {
      while (temp->next != NULL) {
        length++;
        temp = temp->next;
      }
      return length;
    }
  }
};

int main() {
  srand(time(NULL));

  Queue myStore;

  int customerCount = 0;
  int queue_length_sum = 0;
  int wait_time_sum = 0;
  int service_time_sum = 0;
  int min_wait_time = 9999;
  int max_wait_time = -1;
  int max_wait_timeTime;
  int max_service_timeTime;
  int max_queue_sizeTime;
  int min_service_timeTime;
  int min_wait_timeTime;
  int min_queue_sizeTime;
  int min_service_time = 9999;
  int max_service_time = -1;
  int max_queue_size = -1;
  int orderTime;

  int random_number;

  while (storeClock < 1020) {
    storeClock++;
    if (storeClock <= 120) {
      random_number = rand() % 10 + 1;
      if (random_number <= 3) {
        // cout << "At time: " << storeClock << " we have 1 new customer" <<
        // endl;
        customerCount++;
        myStore.enqueue();
      }
    } else if (storeClock <= 210) {
      random_number = rand() % 10 + 1;
      if (random_number <= 1) {
        // cout << "At time: " << storeClock << " we have 1 new customer" <<
        // endl;
        customerCount++;
        myStore.enqueue();
      }
    } else if (storeClock <= 330) {
      random_number = rand() % 10 + 1;
      if (random_number <= 4) {
        // cout << "At time: " << storeClock << " we have 1 new customer" <<
        // endl;
        customerCount++;
        myStore.enqueue();
      }
    } else if (storeClock <= 570) {
      random_number = rand() % 10 + 1;
      if (random_number <= 1) {
        // cout << "At time: " << storeClock << " we have 1 new customer" <<
        // endl;
        customerCount++;
        myStore.enqueue();
      }
    } else if (storeClock <= 720) {
      random_number = rand() % 100 + 1;
      if (random_number <= 25) {
        // cout << "At time: " << storeClock << " we have 1 new customer" <<
        // endl;
        customerCount++;
        myStore.enqueue();
      }
    } else if (storeClock <= 900) {
      random_number = rand() % 10 + 1;
      if (random_number <= 2) {
        // cout << "At time: " << storeClock << " we have 1 new customer" <<
        // endl;
        customerCount++;
        myStore.enqueue();
      }
    } else if (storeClock <= 1020) {
      random_number = rand() % 10 + 1;
      if (random_number <= 1) {
        // cout << "At time: " << storeClock << " we have 1 new customer" <<
        // endl;
        customerCount++;
        myStore.enqueue();
      }
    }

    if (myStore.head != NULL) {
      if (myStore.head->orderTime == 0) {
        service_time_sum += (storeClock - myStore.head->inTime);
        if ((storeClock - myStore.head->inTime) < min_service_time) {
          min_service_time = (storeClock - myStore.head->inTime);
          min_service_timeTime = storeClock;
        }
        if ((storeClock - myStore.head->inTime) > max_service_time) {
          max_service_time = (storeClock - myStore.head->inTime);
          max_service_timeTime = storeClock;
        }
        if ((storeClock - myStore.head->inTime) < min_service_time) {
          min_service_time = (storeClock - myStore.head->inTime);
          min_service_timeTime = storeClock;
        }
        myStore.dequeue();
        if (myStore.head != NULL) {
          wait_time_sum += (storeClock - myStore.head->inTime);
          if ((storeClock - myStore.head->inTime) < min_wait_time) {
            min_wait_time = (storeClock - myStore.head->inTime);
            min_wait_timeTime = storeClock;
          }
          if ((storeClock - myStore.head->inTime) > max_wait_time) {
            max_wait_time = (storeClock - myStore.head->inTime);
            max_wait_timeTime = storeClock;
          }
        }
      } else {
        myStore.head->orderTime--;
      }
    }
    queue_length_sum += myStore.queueSize();
    if (max_queue_size < myStore.queueSize()) {
      max_queue_size = myStore.queueSize();
      max_queue_sizeTime = storeClock;
    }
  }
  cout << "Average customer wait time: " << (wait_time_sum / customerCount)
       << endl;
  cout << "Average customer Service time: "
       << (service_time_sum / customerCount) << endl;
  cout << "Average queue length: " << (queue_length_sum / 1020) << endl;
  cout << "Maximum wait time: " << max_wait_time << " at "
       << toTime(max_wait_timeTime) << endl;
  cout << "Maximum service time: " << max_service_time << " at "
       << toTime(max_service_timeTime) << endl;
  cout << "Longest line: " << max_queue_size << " at "
       << toTime(max_queue_sizeTime) << endl;
  cout << "Minimum queue length: 0 at 8:00AM" << endl;
  cout << "Minimum service time: " << min_service_time << " at "
       << toTime(min_service_timeTime) << endl;
  cout << "Minimum wait time: 0 at 8:00AM" << endl;
  cout << "Shortest Line: 0 at 8:00AM" << endl;
}