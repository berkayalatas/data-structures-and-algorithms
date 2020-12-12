//first solution
function isAnagram(str1,str2) {
    if(str1.length != str2.length)
        return false

    for(var i=0 ; i< str1.length ; i++){
        var indx = str2.indexOf(str1[i]);
        if(indx == -1)
            return false
        str2 = str2.substring(0,indx) + str2.substring(indx+1);    
    }    
    return true;
}
//second way
function isAnagram(str1,str2) {
    if(str1.length != str2.length)
        return false

    var count1 = {};
    var count2 = {};
    var ch;

    for(i=0 ; i<str1.length ; i++){
        ch = str1[i];
        count1[ch] = ++count1[ch] || 1;
    }

    for(i=0 ; i<str2.length ; i++){
        ch = str2[i];
        count2[ch] = ++count2[ch] || 1;
    }

    var keys = Object.keys(count1);

    for(ch = 0 ; ch< keys.length ; ch++){
        if(
            !count2[keys[ch] || count1[keys[ch]] !== count2[keys[ch]]]
        ){
            return false;
        }
    }

    return true;

}




function concatenationsSum(a) {
    let inimSum = 0;
    let offsetSum = 0;
   a.forEach(el => {
      inimSum += el;

      const size = el.toString().length;
      const offset = Math.pow(10, size);
      offsetSum += offset;
   });

   return inimSum * a.length + inimSum * offsetSum;
}



//interview question
function stringMerge(str1 , str2){

    let newStr = "";

    for(let i=0 ; i < str1.length || str2.length ; i++ ){

        if(i<str1.length)
            newStr += str1[i];

        if(i<str2.length)
            newStr += str2[i];    

    }
        return newStr;

}

/* 

Given a sequence of integers as an array, 
determine whether it is possible to obtain a strictly 
increasing sequence by removing no more than one element
from the array.

Note: sequence a0, a1, ..., an is considered to be a 
strictly increasing if a0 < a1 < ... < an. Sequence 
containing only one element is also considered to be 
strictly increasing.

Example

For sequence = [1, 3, 2, 1], the output should be
almostIncreasingSequence(sequence) = false.

There is no one element in this array that can be 
removed in order to get a strictly increasing sequence.

For sequence = [1, 3, 2], the output should be
almostIncreasingSequence(sequence) = true.

You can remove 3 from the array to get the strictly increasing sequence [1, 2]. Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].

*/
function almostIncreasingSequence(sequence) {
    var found = false;
    for (var i=0;i<sequence.length;i++) 
    {  
      if(sequence[i] <= sequence[i-1]) 
      {  
        if(found) 
          return false;
        
        found = true;
        
        if(i === 1 || i + 1 === sequence.length) 
          continue;
        
        else if (sequence[i] > sequence[i-2]) 
          sequence[i-1] = sequence[i-2];
        
        else if(sequence[i-1] >= sequence[i+1]) 
          return false;
        
      }
    }
    return true;
}

//second way
function almostIncreasingSequence(sequence) {    
    if(sequence.length == 2) return true;

    var error = 0;

    for(var i = 0; i < sequence.length - 1; i++){
        // if current value is greater than next value
        if(sequence[i] >= sequence[i+1]){
            // Test whether stepping back or forwards can bridge the hump or pothole
            var noStepBack = sequence[i-1] && sequence[i-1] >= sequence[i+1];
            var noStepFoward = sequence[i+2] && sequence[i] >= sequence[i+2];
            // We only test for bridge gaps when i > 0
            if(i > 0 && noStepBack && noStepFoward) {
                // Cannot step back over gap forwards or backwards
                // Counts as two errors ONLY WHEN BOTH PRESENT
                error+=2;
            }else{
                // Typical error
                error++;
            }
        }

        // Early dropout cause if you ever get more than one error, then its game over anyway
        if(error > 1) return false;
    }

    return true;
}


//3.way
function almostIncreasingSequence(sequence) {
    var danger=0;
 
    for(let i=0 ; i<sequence.length ; i++) {
        if (sequence[i] <= sequence[i-1])
            danger++;
        if(danger > 1)
            return false;
            
        if(sequence[i] <= sequence[i-2] && sequence[i+1] <= sequence[i-1])
            return false;        
    }
    return true;
}

/*
After becoming famous, the CodeBots decided to move into a new building together. Each of the rooms has a different cost, and some of them are free, but there's a rumour that all the free rooms are haunted! Since the CodeBots are quite superstitious, they refuse to stay in any of the free rooms, or any of the rooms below any of the free rooms.

Given matrix, a rectangular matrix of integers, where each value represents the cost of the room, your task is to return the total sum of all rooms that are suitable for the CodeBots (ie: add up all the values that don't appear below a 0).

Example

For

matrix = [[0, 1, 1, 2], 
          [0, 5, 0, 0], 
          [2, 0, 3, 3]]
the output should be
matrixElementsSum(matrix) = 9.

example 1

There are several haunted rooms, so we'll disregard them as well as any rooms beneath them. Thus, the answer is 1 + 5 + 1 + 2 = 9.

For

matrix = [[1, 1, 1, 0], 
          [0, 5, 0, 1], 
          [2, 1, 3, 10]]
the output should be
matrixElementsSum(matrix) = 9.
*/
function matrixElementsSum(matrix) {
    let sum =0;
        for(let i =0; i<matrix[0].length;i++) {
            for(let j=0; j<matrix.length;j++) {
                if(matrix[j][i] > 0)
                    sum +=matrix[j][i];
                else
                    break;
            }
        }
        return sum;
}


