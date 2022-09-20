#ifndef FINDUNFITINPUTS
#define FINDUNFITINPUTS
#include<vector>
#include<random>
// 書き途中　分かりやすい様に入力と自分と正解の出力をどっかに出力したいけれど、どうやったら分かりやすいか考え中
struct input{
    // please write problems' inputs
};
struct output{
    // please write problems' outputs

    static bool equal(const output &out0, const output out1){
        // equal condition
        return true;
    }
};

input create_random_input(){
    input in;
    // create random input with constrains
    return in;
}

output create_collect_output(input in){
    output out;
    // fill here collect but slow algorithm that solve the problem
    //
    return out;
}

output create_my_output(input in) {
    output out;
    // fill here collect but slow algorithm that solve the problem
    //
    return out;
}

std::vector<input> find_unfit_inputs(int roop_num){
    std::vector<input> unfit_inputs;
    for(int i=0;i<roop_num;++i){
        input in = create_random_input();
        output collect_output = create_collect_output(in);
        output my_output = create_my_output(in);
        if(!output::equal(collect_output, my_output)) unfit_inputs.push_back(in); 
    }
    return unfit_inputs;
}
#endif