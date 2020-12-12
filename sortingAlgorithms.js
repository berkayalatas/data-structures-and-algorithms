//insertion sort

function insertSort(arr){

    for(let i=1; i<arr.length ; i++){
        let key = arr[i];
        let j = i-1;

        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;

    }
    return arr;
}

let arr = [1,3,2,9,1,25]

//console.log(insertSort(arr));


/*
function insertSort(arr){

    for(let i=1; i<arr.length ; i++){
        let current = arr[i];
        let position = i;

        while(position>=0 && arr[position-1] > current)
        {
            arr[position] = arr[position-1];
            position--;
        }

        arr[position] = current;

    }
    return arr;
}

let arr = [1,3,2,9,1,25]

console.log(insertSort(arr));
*/



/*Selection Sort */

function selectionSort(arr){

    for(let i=0; i < arr.length-1 ; i++){
        let smaller_indx = i;

        for(let j=i+1 ; j<arr.length ; j++)
            if(arr[j] < arr[smaller_indx])
                smaller_indx = j;

        let temp = arr[smaller_indx];
        arr[smaller_indx] = arr[i];
        arr[i] = temp;
        

    }
    return arr;

}

let array = [1,5,2,5,3,6];

//console.log(selectionSort(array));


//Bubble Sort


/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

Third Pass:
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

*/

function bubble_sort(arr){

    let long = arr.length-1;
    let isSorted = false;

    while(!isSorted){
        isSorted=true;

        for(let i=0 ; i<long ; i++){
            if(arr[i] > arr[i+1])
            {
                let temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isSorted = false;
            }
        }
        long--;
    }
    return arr;
}

let ar = [1,9,3,5,6,2]

//console.log(bubble_sort(ar));
//[ 1, 2, 3, 5, 6, 9 ]

//or

function bubbleSort(arr){

    let distance = arr.length-1;

    for(let i=0 ; i<distance ; i++){

        for(let j=0 ; j<distance-i ; j++)
            if(arr[j] > arr[j+1] ){
                let temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        
    }
    return arr;
}

let new_arr = [50,90,30,40,10,20];

console.log(bubbleSort(new_arr));