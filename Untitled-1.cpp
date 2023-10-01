
    void callStageone(){

        if(circle_cleared && stage_two_flag && !diamond_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_one();
                transition_done = false;
                stage_two_flag = false;
            }
            else{
                transition_done = false;
                stage_two_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                triangle_skipped = true;
            }

        }else if(!triangle_skipped &&diamond_cleared && stage_two_flag && !cross_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_one();
                transition_done = false;
                stage_two_flag = false;
            }
            else{
                transition_done = false;
                stage_two_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                cross_skipped = true;
            }
        }else if(!boss[random_boss]->monster_done && diamond_cleared && circle_cleared && cross_cleared && stage_two_flag ){
            transition_done = false;
            stage_two_flag = false;
            boss[random_boss]->monster_bool = true;
            boss[random_boss]->monster_done = false;
            boss[random_boss]->monster_right = false;
            boss[random_boss]->monster_timer = 90000000;
            boss[random_boss]->monster_uptodown_transition = false;
            //Stage_one_completed = true;
        }

        // cout<<"Cp6"<<endl;
        
        
        if(boss[random_boss]->monster_done && triangle_skipped){
            diamond_cleared = false;
            triangle_skipped = false;
            stage_two_flag = true;
        }else if(boss[random_boss]->monster_bool && cross_skipped){
            cross_cleared = false;
            cross_skipped = false;
            stage_two_flag = true;
        }
        // cout<<"boss[0]->monster_done "<<boss[0]->monster_done<<endl;
        // cout<<"!diamond_cleared"<<!diamond_cleared<<endl;
        // cout<<"!cross_cleared"<<!cross_cleared<<endl;

        if(boss[random_boss]->monster_done && (!diamond_cleared || !cross_cleared)){
            // cout<<"In the first if cond "<<endl; 
            if(!diamond_cleared && stage_two_flag){
                // cout<<"In the 2nd if cond "<<endl; 
                Stage_one();
                transition_done = false;
                stage_two_flag = false;
                // diamond_cleared = true;
            }
            else if(!cross_cleared && stage_two_flag){
                Stage_one();
                transition_done = false;
                stage_two_flag = false;
                // cross_cleared = true;
            }

            if(diamond_cleared && cross_cleared){
                boss[random_boss]->monster_done = false;
            }

        } 

        if(!transition_done && circle_cleared && !diamond_cleared && !boss[random_boss]->monster_bool){
            transition_up_to_down();
        }
        //cout<<"!tran"<<!transition_done<<" and "<<"tri clear "<<diamond_cleared<<endl;
        if(!transition_done && diamond_cleared && !boss[random_boss]->monster_bool){
            crossTransition(5);
            if(!diamond_cleared && !boss[random_boss]->monster_done){
                diamond_cleared = true;
                boss[random_boss]->monster_done = true;
            }
            //cout<<"transition"<<endl;
        }
        //cout<<"hi"<<endl;
        if(cross_cleared && stage_two_flag){
            rebalancing();
            stage_two_flag = false;
        }
        // cout<<"Cp7"<<endl;
    
    }