/**
 * 
 * inputs from ctc:
 * -> connection[0] -> connection to track model
 * -> authority from CTC[1] -> read from db 
 * -> suggested speed from CTC[2:9] -> read from db 
 * -> left switch position from CTC[10] -> read from db 
 * -> right switch position from CTC[11] -> read from db 

 * 
 * inputs from track model (db):
 * -> connection[16] -> connection to track model
 * -> prevprev occupancy[17] -> read from db
 * -> prev occypancy[18] -> read from db
 * -> curr occupancy[19] -> read from db
 * -> next occupancy[20] -> read from db
 * -> nextnext occupancy[21] -> read from db
 * -> temperature from current Track Model[22:29] -> read from db
 * -> failure mode[30:31] -> read from db
 * 
 * 
 * outputs to ctc:
 * -> curr occupancy[0] -> read from db -> do nothing
 * -> failure mode[1:2] -> read from db -> do nothing
 * 
 * outputs to track model
 * -> left switch position from CTC[16] -> read from db -> do nothing
 * -> right switch position from CTC[17] -> read from db -> do nothing
 * -> light signal to prev[18:19] -> check prev occupancy and prev prev occupancy -> write to db
 * -> light signal to next[20:21]-> check next occupancy and next next occupancy -> write to db
 * -> crossing[22]  -> check prev occupancy and prev prev occupancy and next occupancy and next next occupancy -> write to db
 * -> heater[23] -> check temperature from current track model -> write to db
 * -> prev occupancy[24]
 * -> next occupancy[25]
 * 
 * outputs to beacon
 * -> authority from CTC[4] -> read from db AS LONG AS CONNECTIONS OK -> pass to beacon -> do nothing
 * -> commanded speed[5:12] -> read from db AS LONG AS CONNECTIONS OK -> pass to beacon -> do nothing
 */


/**
 * 
 * @param {number} inputs_32 
 * @return {number} outputs_32
 */
function plc(inputs_32) {
    //Parsing input binaries
    let ctc_in_connection_1
        = (inputs_32 | (0b00000001 << 0)) >> 0;
    let ctc_in_authority_1
        = (inputs_32 | (0b00000001 << 1)) >> 1;
    let ctc_in_suggspeed_8
        = (inputs_32 | (0b11111111 << 2)) >> 2;
    let ctc_in_leftswitchposi_1
        = (inputs_32 | (0b00000001 << 10)) >> 10;
    let ctc_in_rightswitchposi_1
        = (inputs_32 | (0b00000001 << 11)) >> 11;
    let km_in_connection_1
        = (inputs_32 | (0b00000001 << 16)) >> 16;
    let km_in_prev2occup_1
        = (inputs_32 | (0b00000001 << 17)) >> 17;
    let km_in_prevoccup_1
        = (inputs_32 | (0b00000001 << 18)) >> 18;
    let km_in_curroccup_1
        = (inputs_32 | (0b00000001 << 19)) >> 19;
    let km_in_nextoccup_1
        = (inputs_32 | (0b00000001 << 20)) >> 20;
    let km_in_next2occup_1
        = (inputs_32 | (0b00000001 << 21)) >> 21;
    let km_in_temperature_8
        = (inputs_32 | (0b11111111 << 22)) >> 22;
    let km_in_failure_2
        = (inputs_32 | (0b00000011 << 30)) >> 30;

    let ctc_out_curroccup_1
        = km_in_curroccup_1;
    let ctc_out_failure_2
        = km_in_failure_2;
    let bcn_out_authority_1
        = ctc_in_authority_1;
    let bcn_out_commspeed_8
        = ctc_in_suggspeed_8;
    let km_out_leftswitposi_1
        = ctc_in_leftswitchposi_1;
    let km_out_rightswitposi_1
        = ctc_in_rightswitchposi_1;
    let km_out_lightsignaltoprev_2
        = ((!km_in_prev2occup_1) << 1) | (!km_in_prev2occup_1) | (km_in_prevoccup_1);
    let km_out_lightsignaltonext_2
        = ((!km_in_next2occup_1) << 1) | (!km_in_next2occup_1) | (km_in_nextoccup_1);
    let km_out_crossing_1
        = km_in_prev2occup_1 | km_in_prevoccup_1 | km_in_nextoccup_1 | km_in_next2occup_1;
    let km_out_heater_1
        = km_in_temperature_8 < 10;
    let km_out_prevoccup_1
        = km_in_prevoccup_1;
    let km_out_nextoccup_1
        = km_in_nextoccup_1;


    let outputs_32 
        = (ctc_out_curroccup_1 << 0)
        |(ctc_out_failure_2<<1)
        |(bcn_out_authority_1<<4)
        |(bcn_out_commspeed_8<<5)
        |(km_out_leftswitposi_1<<16)
        |(km_out_rightswitposi_1<<17)
        |(km_out_lightsignaltoprev_2<<18)
        |(km_out_lightsignaltonext_2<<20)
        |(km_out_crossing_1<<22)
        |(km_out_heater_1<<23)
        |(km_out_prevoccup_1<<24)
        |(km_out_nextoccup_1<<25);

    return outputs_32;

}