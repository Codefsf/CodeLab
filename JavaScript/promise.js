'use strict'

/*
js中处理回到问题的办法：
1.参数回调
2.promise
*/

//参数回调方法
var parm = {
    num : 10,
    call : callBack
}

function callBack(num)
{
    console.log("callback+ " + num + " " + Date.now());
}

function test(parm) {
    parm.call(parm.num);
}

//test(parm);


//Promise方法
function testPromise()
{
    var pro = new Promise(function(resolve, reject) {
        console.log('Start promise');
    
        setTimeout(function(){
            var time = Date.now() % 2;
            console.log('Time num:' + time);
        
            if (time == 0) {
                resolve('done');
            } else {
                reject('error');
            }
    
        }, 1000);
    }).then(function(result) {
        console.log('Then:' + result);
    }).catch(function(error){
        console.log('Catch:' + error);
    });
}

//Promise串行处理任务
function testJobsPromise()
{
    function job2(parm){
        return new Promise(function(resolve, reject){
            console.log('Start promise job2 ' + parm);
            resolve(parm + 123);
        })
    }

    function job3(parm){
        return new Promise(function(resolve, reject){
            console.log('Start promise job3 ' + parm);
            resolve(parm + 123);
        })
    } 
    new Promise(function(resolve, reject){
        console.log('Start promise job1');
        resolve(123);
    }).then(job2)
    .then(job3)
    .catch(function(){});
}

//testJobsPromise();

//Promise并行执行异步任务
function testParallelJob()
{
    var arr = [];

    var p1 = new Promise(function(resolve, reject){
        setTimeout(resolve, 500, '111');
    });

    var p2 = new Promise(function(resolve, reject){
        setTimeout(resolve, 600, '222');
    });

    arr.push(p1);
    arr.push(p2);

    Promise.all(arr).then(function(result){
        console.log('Result:' + result);
    });
}

testParallelJob();