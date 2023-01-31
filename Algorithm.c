//Algorithm specific implementation
//----------------------------------------------------------------//


//Linear Search
function linearSearch(list, target) {
  for (i = 0; i < list.length; i++) {
    if (list[i] == target) {
      return i;
    }
  }
  return -1;
}

//Binary search
function binarySearch(list, target) {
  let low = 0, high = list.length - 1;
  while (low <= high) {
    let mid = Math.floor((low + high) / 2);
    if (list[mid] == target) {
      return mid;
    } else if (list[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

//Selection Sort
function selectionSort(list) {
  for (let i = 0; i < list.length - 1; i++) {
    let minIndex = i;
    for (let j = i + 1; j < list.length; j++) {
      if (list[j] < list[minIndex]) {
        minIndex = j;
      }
    }
    let temp = list[i];
    list[i] = list[minIndex];
    list[minIndex] = temp;
  }
  return list;
}

//Bubble Sort
function bubbleSort(list) {
  for (let i = 0; i < list.length; i++) {
    for (let j = 0; j < list.length - i - 1; j++) {
      if (list[j] > list[j + 1]) {
        let temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }
  return list;
}

//Insertion Sort
function insertionSort(list) {
  for (let i = 1; i < list.length; i++) {
    let key = list[i];
    let j = i - 1;
    while (j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j--;
    }
    list[j + 1] = key;
  }
  return list;
}


//Merge Sort
function mergeSort(list) {
  if (list.length <= 1) return list;
  let middle = Math.floor(list.length / 2);
  let left = list.slice(0, middle);
  let right = list.slice(middle);
  left = mergeSort(left);
  right = mergeSort(right);
  return merge(left, right);
}

function merge(left, right) {
  let result = [];
  let i = 0, j = 0;
  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      result.push(left[i]);
      i++;
    } else {
      result.push(right[j]);
      j++;
    }
  }
  while (i < left.length) {
    result.push(left[i]);
    i++;
  }
  while (j < right.length) {
    result.push(right[j]);
    j++;
  }
  return result;
}

//Himanshu Raj

//Quick Sort
function quickSort(list, low, high) {
  if (low < high) {
    let pivotIndex = partition(list, low, high);
    quickSort(list, low, pivotIndex);
    quickSort(list, pivotIndex + 1, high);
  }
  return list;
}

function partition(list, low, high) {
  let pivot = list[high];
  let i = low - 1;
  for (let j = low; j < high; j++) {
    if (list[j] <= pivot) {
      i++;
      let temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }
  let temp = list[i + 1];
  list[i + 1] = list[high];
  list[high] = temp;
  return i + 1;
}
