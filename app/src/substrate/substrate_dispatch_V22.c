/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include "substrate_dispatch_V22.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V22(
    parser_context_t* c, pd_balances_transfer_allow_death_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V22(
    parser_context_t* c, pd_balances_force_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V22(
    parser_context_t* c, pd_balances_transfer_keep_alive_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V22(
    parser_context_t* c, pd_balances_transfer_all_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V22(
    parser_context_t* c, pd_balances_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V22(
    parser_context_t* c, pd_staking_bond_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V22(
    parser_context_t* c, pd_staking_bond_extra_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V22(
    parser_context_t* c, pd_staking_unbond_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V22(
    parser_context_t* c, pd_staking_withdraw_unbonded_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V22(
    parser_context_t* c, pd_staking_validate_V22_t* m)
{
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V22(
    parser_context_t* c, pd_staking_nominate_V22_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V22(
    parser_context_t* c, pd_staking_chill_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V22(
    parser_context_t* c, pd_staking_set_payee_V22_t* m)
{
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V22(
    parser_context_t* c, pd_staking_set_controller_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V22(
    parser_context_t* c, pd_staking_payout_stakers_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V22(
    parser_context_t* c, pd_staking_rebond_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V22(
    parser_context_t* c, pd_session_set_keys_V22_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V22(
    parser_context_t* c, pd_session_purge_keys_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V22(
    parser_context_t* c, pd_utility_batch_V22_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V22(
    parser_context_t* c, pd_utility_batch_all_V22_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V22(
    parser_context_t* c, pd_utility_force_batch_V22_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_create_V22(
    parser_context_t* c, pd_crowdloan_create_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    CHECK_ERROR(_readCompactu32(c, &m->first_period))
    CHECK_ERROR(_readCompactu32(c, &m->last_period))
    CHECK_ERROR(_readCompactu32(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_contribute_V22(
    parser_context_t* c, pd_crowdloan_contribute_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readOptionMultiSignature(c, &m->signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_withdraw_V22(
    parser_context_t* c, pd_crowdloan_withdraw_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->who))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_refund_V22(
    parser_context_t* c, pd_crowdloan_refund_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_dissolve_V22(
    parser_context_t* c, pd_crowdloan_dissolve_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_edit_V22(
    parser_context_t* c, pd_crowdloan_edit_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    CHECK_ERROR(_readCompactu32(c, &m->first_period))
    CHECK_ERROR(_readCompactu32(c, &m->last_period))
    CHECK_ERROR(_readCompactu32(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_add_memo_V22(
    parser_context_t* c, pd_crowdloan_add_memo_V22_t* m)
{
    CHECK_ERROR(_readParaId(c, &m->index))
    CHECK_ERROR(_readVecu8(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_poke_V22(
    parser_context_t* c, pd_crowdloan_poke_V22_t* m)
{
    CHECK_ERROR(_readParaId(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_contribute_all_V22(
    parser_context_t* c, pd_crowdloan_contribute_all_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readOptionMultiSignature(c, &m->signature))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_xcmpallet_teleport_assets_V22(
    parser_context_t* c, pd_xcmpallet_teleport_assets_V22_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xcmpallet_reserve_transfer_assets_V22(
    parser_context_t* c, pd_xcmpallet_reserve_transfer_assets_V22_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xcmpallet_limited_reserve_transfer_assets_V22(
    parser_context_t* c, pd_xcmpallet_limited_reserve_transfer_assets_V22_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xcmpallet_limited_teleport_assets_V22(
    parser_context_t* c, pd_xcmpallet_limited_teleport_assets_V22_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V22(
    parser_context_t* c, pd_system_remark_V22_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V22(
    parser_context_t* c, pd_system_set_heap_pages_V22_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V22(
    parser_context_t* c, pd_system_set_code_V22_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V22(
    parser_context_t* c, pd_system_set_code_without_checks_V22_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V22(
    parser_context_t* c, pd_system_remark_with_event_V22_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V22(
    parser_context_t* c, pd_timestamp_set_V22_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V22(
    parser_context_t* c, pd_indices_claim_V22_t* m)
{
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V22(
    parser_context_t* c, pd_indices_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V22(
    parser_context_t* c, pd_indices_free_V22_t* m)
{
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V22(
    parser_context_t* c, pd_indices_force_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V22(
    parser_context_t* c, pd_indices_freeze_V22_t* m)
{
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_deprecated_V22(
    parser_context_t* c, pd_balances_set_balance_deprecated_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->old_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V22(
    parser_context_t* c, pd_balances_force_unreserve_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V22(
    parser_context_t* c, pd_balances_upgrade_accounts_V22_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V22(
    parser_context_t* c, pd_balances_force_set_balance_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V22(
    parser_context_t* c, pd_staking_set_validator_count_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V22(
    parser_context_t* c, pd_staking_increase_validator_count_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V22(
    parser_context_t* c, pd_staking_scale_validator_count_V22_t* m)
{
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V22(
    parser_context_t* c, pd_staking_force_no_eras_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V22(
    parser_context_t* c, pd_staking_force_new_era_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V22(
    parser_context_t* c, pd_staking_set_invulnerables_V22_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V22(
    parser_context_t* c, pd_staking_force_unstake_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V22(
    parser_context_t* c, pd_staking_force_new_era_always_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V22(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V22_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V22(
    parser_context_t* c, pd_staking_reap_stash_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V22(
    parser_context_t* c, pd_staking_kick_V22_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V22(
    parser_context_t* c, pd_staking_set_staking_configs_V22_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V22(
    parser_context_t* c, pd_staking_chill_other_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V22(
    parser_context_t* c, pd_staking_force_apply_min_commission_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_commission_V22(
    parser_context_t* c, pd_staking_set_min_commission_V22_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V22(
    parser_context_t* c, pd_treasury_propose_spend_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V22(
    parser_context_t* c, pd_treasury_reject_proposal_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V22(
    parser_context_t* c, pd_treasury_approve_proposal_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_spend_V22(
    parser_context_t* c, pd_treasury_spend_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_remove_approval_V22(
    parser_context_t* c, pd_treasury_remove_approval_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_vote_V22(
    parser_context_t* c, pd_convictionvoting_vote_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->poll_index))
    CHECK_ERROR(_readAccountVote(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_delegate_V22(
    parser_context_t* c, pd_convictionvoting_delegate_V22_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->to))
    CHECK_ERROR(_readConviction(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_undelegate_V22(
    parser_context_t* c, pd_convictionvoting_undelegate_V22_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_unlock_V22(
    parser_context_t* c, pd_convictionvoting_unlock_V22_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_remove_vote_V22(
    parser_context_t* c, pd_convictionvoting_remove_vote_V22_t* m)
{
    CHECK_ERROR(_readOptionClassOf(c, &m->class_))
    CHECK_ERROR(_readPollIndexOf(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_remove_other_vote_V22(
    parser_context_t* c, pd_convictionvoting_remove_other_vote_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readPollIndexOf(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_place_decision_deposit_V22(
    parser_context_t* c, pd_referenda_place_decision_deposit_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_refund_decision_deposit_V22(
    parser_context_t* c, pd_referenda_refund_decision_deposit_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_cancel_V22(
    parser_context_t* c, pd_referenda_cancel_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_kill_V22(
    parser_context_t* c, pd_referenda_kill_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_nudge_referendum_V22(
    parser_context_t* c, pd_referenda_nudge_referendum_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_one_fewer_deciding_V22(
    parser_context_t* c, pd_referenda_one_fewer_deciding_V22_t* m)
{
    CHECK_ERROR(_readTrackIdOf(c, &m->track))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_refund_submission_deposit_V22(
    parser_context_t* c, pd_referenda_refund_submission_deposit_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_set_metadata_V22(
    parser_context_t* c, pd_referenda_set_metadata_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    CHECK_ERROR(_readOptionPreimageHash(c, &m->maybe_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_add_member_V22(
    parser_context_t* c, pd_fellowshipcollective_add_member_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_promote_member_V22(
    parser_context_t* c, pd_fellowshipcollective_promote_member_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_demote_member_V22(
    parser_context_t* c, pd_fellowshipcollective_demote_member_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_remove_member_V22(
    parser_context_t* c, pd_fellowshipcollective_remove_member_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readRank(c, &m->min_rank))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_vote_V22(
    parser_context_t* c, pd_fellowshipcollective_vote_V22_t* m)
{
    CHECK_ERROR(_readPollIndexOf(c, &m->poll))
    CHECK_ERROR(_readbool(c, &m->aye))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_cleanup_poll_V22(
    parser_context_t* c, pd_fellowshipcollective_cleanup_poll_V22_t* m)
{
    CHECK_ERROR(_readPollIndexOf(c, &m->poll_index))
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_place_decision_deposit_V22(
    parser_context_t* c, pd_fellowshipreferenda_place_decision_deposit_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_refund_decision_deposit_V22(
    parser_context_t* c, pd_fellowshipreferenda_refund_decision_deposit_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_cancel_V22(
    parser_context_t* c, pd_fellowshipreferenda_cancel_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_kill_V22(
    parser_context_t* c, pd_fellowshipreferenda_kill_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_nudge_referendum_V22(
    parser_context_t* c, pd_fellowshipreferenda_nudge_referendum_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_one_fewer_deciding_V22(
    parser_context_t* c, pd_fellowshipreferenda_one_fewer_deciding_V22_t* m)
{
    CHECK_ERROR(_readTrackIdOf(c, &m->track))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_refund_submission_deposit_V22(
    parser_context_t* c, pd_fellowshipreferenda_refund_submission_deposit_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_set_metadata_V22(
    parser_context_t* c, pd_fellowshipreferenda_set_metadata_V22_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    CHECK_ERROR(_readOptionPreimageHash(c, &m->maybe_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_whitelist_call_V22(
    parser_context_t* c, pd_whitelist_whitelist_call_V22_t* m)
{
    CHECK_ERROR(_readPreimageHash(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_remove_whitelisted_call_V22(
    parser_context_t* c, pd_whitelist_remove_whitelisted_call_V22_t* m)
{
    CHECK_ERROR(_readPreimageHash(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_dispatch_whitelisted_call_V22(
    parser_context_t* c, pd_whitelist_dispatch_whitelisted_call_V22_t* m)
{
    CHECK_ERROR(_readPreimageHash(c, &m->call_hash))
    CHECK_ERROR(_readu32(c, &m->call_encoded_len))
    CHECK_ERROR(_readWeight(c, &m->call_weight_witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_dispatch_whitelisted_call_with_preimage_V22(
    parser_context_t* c, pd_whitelist_dispatch_whitelisted_call_with_preimage_V22_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_V22(
    parser_context_t* c, pd_claims_claim_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest_V22(
    parser_context_t* c, pd_claims_claim_attest_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest_V22(
    parser_context_t* c, pd_claims_attest_V22_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim_V22(
    parser_context_t* c, pd_claims_move_claim_V22_t* m)
{
    CHECK_ERROR(_readEthereumAddress(c, &m->old))
    CHECK_ERROR(_readEthereumAddress(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V22(
    parser_context_t* c, pd_utility_with_weight_V22_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V22(
    parser_context_t* c, pd_identity_add_registrar_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V22(
    parser_context_t* c, pd_identity_set_identity_V22_t* m)
{
    CHECK_ERROR(_readIdentityInfo(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V22(
    parser_context_t* c, pd_identity_set_subs_V22_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V22(
    parser_context_t* c, pd_identity_clear_identity_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V22(
    parser_context_t* c, pd_identity_request_judgement_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V22(
    parser_context_t* c, pd_identity_cancel_request_V22_t* m)
{
    CHECK_ERROR(_readRegistrarIndex(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V22(
    parser_context_t* c, pd_identity_set_fee_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V22(
    parser_context_t* c, pd_identity_set_account_id_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V22(
    parser_context_t* c, pd_identity_provide_judgement_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readJudgementBalanceOfT(c, &m->judgement))
    CHECK_ERROR(_readHash(c, &m->identity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V22(
    parser_context_t* c, pd_identity_kill_identity_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V22(
    parser_context_t* c, pd_identity_add_sub_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V22(
    parser_context_t* c, pd_identity_rename_sub_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V22(
    parser_context_t* c, pd_identity_remove_sub_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V22(
    parser_context_t* c, pd_identity_quit_sub_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_bid_V22(
    parser_context_t* c, pd_society_bid_V22_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unbid_V22(
    parser_context_t* c, pd_society_unbid_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vouch_V22(
    parser_context_t* c, pd_society_vouch_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readBalanceOf(c, &m->tip))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unvouch_V22(
    parser_context_t* c, pd_society_unvouch_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vote_V22(
    parser_context_t* c, pd_society_vote_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->candidate))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_defender_vote_V22(
    parser_context_t* c, pd_society_defender_vote_V22_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_payout_V22(
    parser_context_t* c, pd_society_payout_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_found_V22(
    parser_context_t* c, pd_society_found_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->founder))
    CHECK_ERROR(_readu32(c, &m->max_members))
    CHECK_ERROR(_readBytes(c, &m->rules))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unfound_V22(
    parser_context_t* c, pd_society_unfound_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_member_V22(
    parser_context_t* c, pd_society_judge_suspended_member_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->forgive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_set_max_members_V22(
    parser_context_t* c, pd_society_set_max_members_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered_V22(
    parser_context_t* c, pd_recovery_set_recovered_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->lost))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V22(
    parser_context_t* c, pd_recovery_initiate_recovery_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V22(
    parser_context_t* c, pd_recovery_vouch_recovery_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->lost))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V22(
    parser_context_t* c, pd_recovery_claim_recovery_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V22(
    parser_context_t* c, pd_recovery_close_recovery_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V22(
    parser_context_t* c, pd_recovery_remove_recovery_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V22(
    parser_context_t* c, pd_recovery_cancel_recovered_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V22(
    parser_context_t* c, pd_vesting_vest_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V22(
    parser_context_t* c, pd_vesting_vest_other_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V22(
    parser_context_t* c, pd_vesting_vested_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V22(
    parser_context_t* c, pd_vesting_force_vested_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V22(
    parser_context_t* c, pd_vesting_merge_schedules_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V22(
    parser_context_t* c, pd_proxy_proxy_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V22(
    parser_context_t* c, pd_proxy_add_proxy_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V22(
    parser_context_t* c, pd_proxy_remove_proxy_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V22(
    parser_context_t* c, pd_proxy_remove_proxies_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V22(
    parser_context_t* c, pd_proxy_create_pure_V22_t* m)
{
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V22(
    parser_context_t* c, pd_proxy_kill_pure_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V22(
    parser_context_t* c, pd_proxy_proxy_announced_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V22(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V22_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V22(
    parser_context_t* c, pd_multisig_as_multi_V22_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V22(
    parser_context_t* c, pd_multisig_approve_as_multi_V22_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V22(
    parser_context_t* c, pd_multisig_cancel_as_multi_V22_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V22(
    parser_context_t* c, pd_preimage_note_preimage_V22_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V22(
    parser_context_t* c, pd_preimage_unnote_preimage_V22_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V22(
    parser_context_t* c, pd_preimage_request_preimage_V22_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V22(
    parser_context_t* c, pd_preimage_unrequest_preimage_V22_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V22(
    parser_context_t* c, pd_bounties_propose_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V22(
    parser_context_t* c, pd_bounties_approve_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V22(
    parser_context_t* c, pd_bounties_propose_curator_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V22(
    parser_context_t* c, pd_bounties_unassign_curator_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V22(
    parser_context_t* c, pd_bounties_accept_curator_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V22(
    parser_context_t* c, pd_bounties_award_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V22(
    parser_context_t* c, pd_bounties_claim_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V22(
    parser_context_t* c, pd_bounties_close_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V22(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_add_child_bounty_V22(
    parser_context_t* c, pd_childbounties_add_child_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readVecu8(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_propose_curator_V22(
    parser_context_t* c, pd_childbounties_propose_curator_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_accept_curator_V22(
    parser_context_t* c, pd_childbounties_accept_curator_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_unassign_curator_V22(
    parser_context_t* c, pd_childbounties_unassign_curator_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_award_child_bounty_V22(
    parser_context_t* c, pd_childbounties_award_child_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_claim_child_bounty_V22(
    parser_context_t* c, pd_childbounties_claim_child_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_close_child_bounty_V22(
    parser_context_t* c, pd_childbounties_close_child_bounty_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nis_place_bid_V22(
    parser_context_t* c, pd_nis_place_bid_V22_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readu32(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nis_retract_bid_V22(
    parser_context_t* c, pd_nis_retract_bid_V22_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readu32(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nis_fund_deficit_V22(
    parser_context_t* c, pd_nis_fund_deficit_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nis_thaw_private_V22(
    parser_context_t* c, pd_nis_thaw_private_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readOptionPerquintill(c, &m->maybe_proportion))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nis_thaw_communal_V22(
    parser_context_t* c, pd_nis_thaw_communal_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nis_communify_V22(
    parser_context_t* c, pd_nis_communify_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nis_privatize_V22(
    parser_context_t* c, pd_nis_privatize_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_transfer_allow_death_V22(
    parser_context_t* c, pd_niscounterpartbalances_transfer_allow_death_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_set_balance_deprecated_V22(
    parser_context_t* c, pd_niscounterpartbalances_set_balance_deprecated_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->new_free))
    CHECK_ERROR(_readCompactu128(c, &m->old_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_force_transfer_V22(
    parser_context_t* c, pd_niscounterpartbalances_force_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_transfer_keep_alive_V22(
    parser_context_t* c, pd_niscounterpartbalances_transfer_keep_alive_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_transfer_all_V22(
    parser_context_t* c, pd_niscounterpartbalances_transfer_all_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_force_unreserve_V22(
    parser_context_t* c, pd_niscounterpartbalances_force_unreserve_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_upgrade_accounts_V22(
    parser_context_t* c, pd_niscounterpartbalances_upgrade_accounts_V22_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_transfer_V22(
    parser_context_t* c, pd_niscounterpartbalances_transfer_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_niscounterpartbalances_force_set_balance_V22(
    parser_context_t* c, pd_niscounterpartbalances_force_set_balance_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voterlist_rebag_V22(
    parser_context_t* c, pd_voterlist_rebag_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dislocated))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voterlist_put_in_front_of_V22(
    parser_context_t* c, pd_voterlist_put_in_front_of_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->lighter))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_join_V22(
    parser_context_t* c, pd_nominationpools_join_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_extra_V22(
    parser_context_t* c, pd_nominationpools_bond_extra_V22_t* m)
{
    CHECK_ERROR(_readBondExtraBalanceOfT(c, &m->extra))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_payout_V22(
    parser_context_t* c, pd_nominationpools_claim_payout_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_V22(
    parser_context_t* c, pd_nominationpools_unbond_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readCompactBalance(c, &m->unbonding_points))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_pool_withdraw_unbonded_V22(
    parser_context_t* c, pd_nominationpools_pool_withdraw_unbonded_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_unbonded_V22(
    parser_context_t* c, pd_nominationpools_withdraw_unbonded_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_create_V22(
    parser_context_t* c, pd_nominationpools_create_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->root))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->nominator))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->bouncer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_create_with_pool_id_V22(
    parser_context_t* c, pd_nominationpools_create_with_pool_id_V22_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->root))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->nominator))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->bouncer))
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_nominate_V22(
    parser_context_t* c, pd_nominationpools_nominate_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_state_V22(
    parser_context_t* c, pd_nominationpools_set_state_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPoolState(c, &m->state))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_metadata_V22(
    parser_context_t* c, pd_nominationpools_set_metadata_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecu8(c, &m->metadata))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_configs_V22(
    parser_context_t* c, pd_nominationpools_set_configs_V22_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_join_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_create_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_pools))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_members))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_members_per_pool))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->global_max_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_update_roles_V22(
    parser_context_t* c, pd_nominationpools_update_roles_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_root))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_nominator))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_bouncer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_chill_V22(
    parser_context_t* c, pd_nominationpools_chill_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_extra_other_V22(
    parser_context_t* c, pd_nominationpools_bond_extra_other_V22_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member))
    CHECK_ERROR(_readBondExtraBalanceOfT(c, &m->extra))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_claim_permission_V22(
    parser_context_t* c, pd_nominationpools_set_claim_permission_V22_t* m)
{
    CHECK_ERROR(_readClaimPermission(c, &m->permission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_payout_other_V22(
    parser_context_t* c, pd_nominationpools_claim_payout_other_V22_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->other))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_V22(
    parser_context_t* c, pd_nominationpools_set_commission_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readOptionTuplePerbillAccountId(c, &m->new_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_max_V22(
    parser_context_t* c, pd_nominationpools_set_commission_max_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPerbill(c, &m->max_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_change_rate_V22(
    parser_context_t* c, pd_nominationpools_set_commission_change_rate_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readCommissionChangeRateBlockNumber(c, &m->change_rate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_commission_V22(
    parser_context_t* c, pd_nominationpools_claim_commission_V22_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fastunstake_register_fast_unstake_V22(
    parser_context_t* c, pd_fastunstake_register_fast_unstake_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fastunstake_deregister_V22(
    parser_context_t* c, pd_fastunstake_deregister_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fastunstake_control_V22(
    parser_context_t* c, pd_fastunstake_control_V22_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->eras_to_check))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_cooldown_V22(
    parser_context_t* c, pd_configuration_set_validation_upgrade_cooldown_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_delay_V22(
    parser_context_t* c, pd_configuration_set_validation_upgrade_delay_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_code_retention_period_V22(
    parser_context_t* c, pd_configuration_set_code_retention_period_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_code_size_V22(
    parser_context_t* c, pd_configuration_set_max_code_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_pov_size_V22(
    parser_context_t* c, pd_configuration_set_max_pov_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_head_data_size_V22(
    parser_context_t* c, pd_configuration_set_max_head_data_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_parathread_cores_V22(
    parser_context_t* c, pd_configuration_set_parathread_cores_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_parathread_retries_V22(
    parser_context_t* c, pd_configuration_set_parathread_retries_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_group_rotation_frequency_V22(
    parser_context_t* c, pd_configuration_set_group_rotation_frequency_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_chain_availability_period_V22(
    parser_context_t* c, pd_configuration_set_chain_availability_period_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_thread_availability_period_V22(
    parser_context_t* c, pd_configuration_set_thread_availability_period_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_scheduling_lookahead_V22(
    parser_context_t* c, pd_configuration_set_scheduling_lookahead_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_per_core_V22(
    parser_context_t* c, pd_configuration_set_max_validators_per_core_V22_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_V22(
    parser_context_t* c, pd_configuration_set_max_validators_V22_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_period_V22(
    parser_context_t* c, pd_configuration_set_dispute_period_V22_t* m)
{
    CHECK_ERROR(_readSessionIndex(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V22(
    parser_context_t* c, pd_configuration_set_dispute_post_conclusion_acceptance_period_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_no_show_slots_V22(
    parser_context_t* c, pd_configuration_set_no_show_slots_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_n_delay_tranches_V22(
    parser_context_t* c, pd_configuration_set_n_delay_tranches_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_zeroth_delay_tranche_width_V22(
    parser_context_t* c, pd_configuration_set_zeroth_delay_tranche_width_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_needed_approvals_V22(
    parser_context_t* c, pd_configuration_set_needed_approvals_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_relay_vrf_modulo_samples_V22(
    parser_context_t* c, pd_configuration_set_relay_vrf_modulo_samples_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_count_V22(
    parser_context_t* c, pd_configuration_set_max_upward_queue_count_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_size_V22(
    parser_context_t* c, pd_configuration_set_max_upward_queue_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_downward_message_size_V22(
    parser_context_t* c, pd_configuration_set_max_downward_message_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_ump_service_total_weight_V22(
    parser_context_t* c, pd_configuration_set_ump_service_total_weight_V22_t* m)
{
    CHECK_ERROR(_readWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_size_V22(
    parser_context_t* c, pd_configuration_set_max_upward_message_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_num_per_candidate_V22(
    parser_context_t* c, pd_configuration_set_max_upward_message_num_per_candidate_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_open_request_ttl_V22(
    parser_context_t* c, pd_configuration_set_hrmp_open_request_ttl_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_sender_deposit_V22(
    parser_context_t* c, pd_configuration_set_hrmp_sender_deposit_V22_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_recipient_deposit_V22(
    parser_context_t* c, pd_configuration_set_hrmp_recipient_deposit_V22_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_capacity_V22(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_capacity_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_total_size_V22(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_total_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V22(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_inbound_channels_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parathread_inbound_channels_V22(
    parser_context_t* c, pd_configuration_set_hrmp_max_parathread_inbound_channels_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_message_size_V22(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_message_size_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V22(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_outbound_channels_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parathread_outbound_channels_V22(
    parser_context_t* c, pd_configuration_set_hrmp_max_parathread_outbound_channels_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_message_num_per_candidate_V22(
    parser_context_t* c, pd_configuration_set_hrmp_max_message_num_per_candidate_V22_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_ump_max_individual_weight_V22(
    parser_context_t* c, pd_configuration_set_ump_max_individual_weight_V22_t* m)
{
    CHECK_ERROR(_readWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_pvf_checking_enabled_V22(
    parser_context_t* c, pd_configuration_set_pvf_checking_enabled_V22_t* m)
{
    CHECK_ERROR(_readbool(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_pvf_voting_ttl_V22(
    parser_context_t* c, pd_configuration_set_pvf_voting_ttl_V22_t* m)
{
    CHECK_ERROR(_readSessionIndex(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_minimum_validation_upgrade_delay_V22(
    parser_context_t* c, pd_configuration_set_minimum_validation_upgrade_delay_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_bypass_consistency_check_V22(
    parser_context_t* c, pd_configuration_set_bypass_consistency_check_V22_t* m)
{
    CHECK_ERROR(_readbool(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_initializer_force_approve_V22(
    parser_context_t* c, pd_initializer_force_approve_V22_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->up_to))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_ump_service_overweight_V22(
    parser_context_t* c, pd_ump_service_overweight_V22_t* m)
{
    CHECK_ERROR(_readOverweightIndex(c, &m->index))
    CHECK_ERROR(_readWeight(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parasdisputes_force_unfreeze_V22(
    parser_context_t* c, pd_parasdisputes_force_unfreeze_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_new_auction_V22(
    parser_context_t* c, pd_auctions_new_auction_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->duration))
    CHECK_ERROR(_readCompactu32(c, &m->lease_period_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_bid_V22(
    parser_context_t* c, pd_auctions_bid_V22_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->para))
    CHECK_ERROR(_readCompactu32(c, &m->auction_index))
    CHECK_ERROR(_readCompactu32(c, &m->first_slot))
    CHECK_ERROR(_readCompactu32(c, &m->last_slot))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_cancel_auction_V22(
    parser_context_t* c, pd_auctions_cancel_auction_V22_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

#endif

parser_error_t _readMethod_V22(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V22_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V22(c, &method->nested.balances_transfer_allow_death_V22))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V22(c, &method->nested.balances_force_transfer_V22))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V22(c, &method->nested.balances_transfer_keep_alive_V22))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V22(c, &method->basic.balances_transfer_all_V22))
        break;
    case 1031: /* module 4 call 7 */
        CHECK_ERROR(_readMethod_balances_transfer_V22(c, &method->nested.balances_transfer_V22))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V22(c, &method->nested.staking_bond_V22))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V22(c, &method->nested.staking_bond_extra_V22))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V22(c, &method->nested.staking_unbond_V22))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V22(c, &method->nested.staking_withdraw_unbonded_V22))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V22(c, &method->basic.staking_validate_V22))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V22(c, &method->nested.staking_nominate_V22))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V22(c, &method->nested.staking_chill_V22))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V22(c, &method->nested.staking_set_payee_V22))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V22(c, &method->nested.staking_set_controller_V22))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V22(c, &method->basic.staking_payout_stakers_V22))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V22(c, &method->nested.staking_rebond_V22))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V22(c, &method->basic.session_set_keys_V22))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V22(c, &method->basic.session_purge_keys_V22))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V22(c, &method->basic.utility_batch_V22))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V22(c, &method->basic.utility_batch_all_V22))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V22(c, &method->basic.utility_force_batch_V22))
        break;
    case 18688: /* module 73 call 0 */
        CHECK_ERROR(_readMethod_crowdloan_create_V22(c, &method->basic.crowdloan_create_V22))
        break;
    case 18689: /* module 73 call 1 */
        CHECK_ERROR(_readMethod_crowdloan_contribute_V22(c, &method->basic.crowdloan_contribute_V22))
        break;
    case 18690: /* module 73 call 2 */
        CHECK_ERROR(_readMethod_crowdloan_withdraw_V22(c, &method->basic.crowdloan_withdraw_V22))
        break;
    case 18691: /* module 73 call 3 */
        CHECK_ERROR(_readMethod_crowdloan_refund_V22(c, &method->basic.crowdloan_refund_V22))
        break;
    case 18692: /* module 73 call 4 */
        CHECK_ERROR(_readMethod_crowdloan_dissolve_V22(c, &method->basic.crowdloan_dissolve_V22))
        break;
    case 18693: /* module 73 call 5 */
        CHECK_ERROR(_readMethod_crowdloan_edit_V22(c, &method->basic.crowdloan_edit_V22))
        break;
    case 18694: /* module 73 call 6 */
        CHECK_ERROR(_readMethod_crowdloan_add_memo_V22(c, &method->basic.crowdloan_add_memo_V22))
        break;
    case 18695: /* module 73 call 7 */
        CHECK_ERROR(_readMethod_crowdloan_poke_V22(c, &method->basic.crowdloan_poke_V22))
        break;
    case 18696: /* module 73 call 8 */
        CHECK_ERROR(_readMethod_crowdloan_contribute_all_V22(c, &method->basic.crowdloan_contribute_all_V22))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        CHECK_ERROR(_readMethod_xcmpallet_teleport_assets_V22(c, &method->basic.xcmpallet_teleport_assets_V22))
        break;
    case 25346: /* module 99 call 2 */
        CHECK_ERROR(_readMethod_xcmpallet_reserve_transfer_assets_V22(c, &method->basic.xcmpallet_reserve_transfer_assets_V22))
        break;
    case 25352: /* module 99 call 8 */
        CHECK_ERROR(_readMethod_xcmpallet_limited_reserve_transfer_assets_V22(c, &method->basic.xcmpallet_limited_reserve_transfer_assets_V22))
        break;
    case 25353: /* module 99 call 9 */
        CHECK_ERROR(_readMethod_xcmpallet_limited_teleport_assets_V22(c, &method->basic.xcmpallet_limited_teleport_assets_V22))
        break;
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V22(c, &method->nested.system_remark_V22))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V22(c, &method->nested.system_set_heap_pages_V22))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V22(c, &method->nested.system_set_code_V22))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V22(c, &method->nested.system_set_code_without_checks_V22))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V22(c, &method->nested.system_remark_with_event_V22))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V22(c, &method->basic.timestamp_set_V22))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V22(c, &method->basic.indices_claim_V22))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V22(c, &method->basic.indices_transfer_V22))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V22(c, &method->basic.indices_free_V22))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V22(c, &method->basic.indices_force_transfer_V22))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V22(c, &method->basic.indices_freeze_V22))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_deprecated_V22(c, &method->nested.balances_set_balance_deprecated_V22))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V22(c, &method->basic.balances_force_unreserve_V22))
        break;
    case 1030: /* module 4 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V22(c, &method->basic.balances_upgrade_accounts_V22))
        break;
    case 1032: /* module 4 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V22(c, &method->basic.balances_force_set_balance_V22))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V22(c, &method->basic.staking_set_validator_count_V22))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V22(c, &method->basic.staking_increase_validator_count_V22))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V22(c, &method->basic.staking_scale_validator_count_V22))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V22(c, &method->basic.staking_force_no_eras_V22))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V22(c, &method->basic.staking_force_new_era_V22))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V22(c, &method->basic.staking_set_invulnerables_V22))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V22(c, &method->basic.staking_force_unstake_V22))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V22(c, &method->basic.staking_force_new_era_always_V22))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V22(c, &method->basic.staking_cancel_deferred_slash_V22))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V22(c, &method->basic.staking_reap_stash_V22))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_kick_V22(c, &method->basic.staking_kick_V22))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_staking_set_staking_configs_V22(c, &method->basic.staking_set_staking_configs_V22))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_staking_chill_other_V22(c, &method->basic.staking_chill_other_V22))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V22(c, &method->basic.staking_force_apply_min_commission_V22))
        break;
    case 1561: /* module 6 call 25 */
        CHECK_ERROR(_readMethod_staking_set_min_commission_V22(c, &method->basic.staking_set_min_commission_V22))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V22(c, &method->basic.treasury_propose_spend_V22))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V22(c, &method->basic.treasury_reject_proposal_V22))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V22(c, &method->basic.treasury_approve_proposal_V22))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_treasury_spend_V22(c, &method->basic.treasury_spend_V22))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_treasury_remove_approval_V22(c, &method->basic.treasury_remove_approval_V22))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_convictionvoting_vote_V22(c, &method->basic.convictionvoting_vote_V22))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_convictionvoting_delegate_V22(c, &method->basic.convictionvoting_delegate_V22))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_convictionvoting_undelegate_V22(c, &method->basic.convictionvoting_undelegate_V22))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_convictionvoting_unlock_V22(c, &method->basic.convictionvoting_unlock_V22))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_convictionvoting_remove_vote_V22(c, &method->basic.convictionvoting_remove_vote_V22))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_convictionvoting_remove_other_vote_V22(c, &method->basic.convictionvoting_remove_other_vote_V22))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_referenda_place_decision_deposit_V22(c, &method->basic.referenda_place_decision_deposit_V22))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_referenda_refund_decision_deposit_V22(c, &method->basic.referenda_refund_decision_deposit_V22))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_referenda_cancel_V22(c, &method->basic.referenda_cancel_V22))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_referenda_kill_V22(c, &method->basic.referenda_kill_V22))
        break;
    case 5381: /* module 21 call 5 */
        CHECK_ERROR(_readMethod_referenda_nudge_referendum_V22(c, &method->basic.referenda_nudge_referendum_V22))
        break;
    case 5382: /* module 21 call 6 */
        CHECK_ERROR(_readMethod_referenda_one_fewer_deciding_V22(c, &method->basic.referenda_one_fewer_deciding_V22))
        break;
    case 5383: /* module 21 call 7 */
        CHECK_ERROR(_readMethod_referenda_refund_submission_deposit_V22(c, &method->basic.referenda_refund_submission_deposit_V22))
        break;
    case 5384: /* module 21 call 8 */
        CHECK_ERROR(_readMethod_referenda_set_metadata_V22(c, &method->basic.referenda_set_metadata_V22))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_fellowshipcollective_add_member_V22(c, &method->basic.fellowshipcollective_add_member_V22))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_fellowshipcollective_promote_member_V22(c, &method->basic.fellowshipcollective_promote_member_V22))
        break;
    case 5634: /* module 22 call 2 */
        CHECK_ERROR(_readMethod_fellowshipcollective_demote_member_V22(c, &method->basic.fellowshipcollective_demote_member_V22))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_fellowshipcollective_remove_member_V22(c, &method->basic.fellowshipcollective_remove_member_V22))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_fellowshipcollective_vote_V22(c, &method->basic.fellowshipcollective_vote_V22))
        break;
    case 5637: /* module 22 call 5 */
        CHECK_ERROR(_readMethod_fellowshipcollective_cleanup_poll_V22(c, &method->basic.fellowshipcollective_cleanup_poll_V22))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_place_decision_deposit_V22(c, &method->basic.fellowshipreferenda_place_decision_deposit_V22))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_refund_decision_deposit_V22(c, &method->basic.fellowshipreferenda_refund_decision_deposit_V22))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_cancel_V22(c, &method->basic.fellowshipreferenda_cancel_V22))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_kill_V22(c, &method->basic.fellowshipreferenda_kill_V22))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_nudge_referendum_V22(c, &method->basic.fellowshipreferenda_nudge_referendum_V22))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_one_fewer_deciding_V22(c, &method->basic.fellowshipreferenda_one_fewer_deciding_V22))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_refund_submission_deposit_V22(c, &method->basic.fellowshipreferenda_refund_submission_deposit_V22))
        break;
    case 5896: /* module 23 call 8 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_set_metadata_V22(c, &method->basic.fellowshipreferenda_set_metadata_V22))
        break;
    case 11264: /* module 44 call 0 */
        CHECK_ERROR(_readMethod_whitelist_whitelist_call_V22(c, &method->basic.whitelist_whitelist_call_V22))
        break;
    case 11265: /* module 44 call 1 */
        CHECK_ERROR(_readMethod_whitelist_remove_whitelisted_call_V22(c, &method->basic.whitelist_remove_whitelisted_call_V22))
        break;
    case 11266: /* module 44 call 2 */
        CHECK_ERROR(_readMethod_whitelist_dispatch_whitelisted_call_V22(c, &method->basic.whitelist_dispatch_whitelisted_call_V22))
        break;
    case 11267: /* module 44 call 3 */
        CHECK_ERROR(_readMethod_whitelist_dispatch_whitelisted_call_with_preimage_V22(c, &method->basic.whitelist_dispatch_whitelisted_call_with_preimage_V22))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V22(c, &method->basic.claims_claim_V22))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V22(c, &method->basic.claims_claim_attest_V22))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V22(c, &method->basic.claims_attest_V22))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V22(c, &method->basic.claims_move_claim_V22))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V22(c, &method->basic.utility_with_weight_V22))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V22(c, &method->basic.identity_add_registrar_V22))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V22(c, &method->basic.identity_set_identity_V22))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V22(c, &method->basic.identity_set_subs_V22))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V22(c, &method->basic.identity_clear_identity_V22))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V22(c, &method->basic.identity_request_judgement_V22))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V22(c, &method->basic.identity_cancel_request_V22))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V22(c, &method->basic.identity_set_fee_V22))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V22(c, &method->basic.identity_set_account_id_V22))
        break;
    case 6409: /* module 25 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V22(c, &method->basic.identity_provide_judgement_V22))
        break;
    case 6410: /* module 25 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V22(c, &method->basic.identity_kill_identity_V22))
        break;
    case 6411: /* module 25 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V22(c, &method->basic.identity_add_sub_V22))
        break;
    case 6412: /* module 25 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V22(c, &method->basic.identity_rename_sub_V22))
        break;
    case 6413: /* module 25 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V22(c, &method->basic.identity_remove_sub_V22))
        break;
    case 6414: /* module 25 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V22(c, &method->basic.identity_quit_sub_V22))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_society_bid_V22(c, &method->basic.society_bid_V22))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_society_unbid_V22(c, &method->basic.society_unbid_V22))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_society_vouch_V22(c, &method->basic.society_vouch_V22))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_society_unvouch_V22(c, &method->basic.society_unvouch_V22))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_society_vote_V22(c, &method->basic.society_vote_V22))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_society_defender_vote_V22(c, &method->basic.society_defender_vote_V22))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_society_payout_V22(c, &method->basic.society_payout_V22))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_society_found_V22(c, &method->basic.society_found_V22))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_society_unfound_V22(c, &method->basic.society_unfound_V22))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_society_judge_suspended_member_V22(c, &method->basic.society_judge_suspended_member_V22))
        break;
    case 6667: /* module 26 call 11 */
        CHECK_ERROR(_readMethod_society_set_max_members_V22(c, &method->basic.society_set_max_members_V22))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V22(c, &method->basic.recovery_set_recovered_V22))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V22(c, &method->basic.recovery_initiate_recovery_V22))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V22(c, &method->basic.recovery_vouch_recovery_V22))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V22(c, &method->basic.recovery_claim_recovery_V22))
        break;
    case 6918: /* module 27 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V22(c, &method->basic.recovery_close_recovery_V22))
        break;
    case 6919: /* module 27 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V22(c, &method->basic.recovery_remove_recovery_V22))
        break;
    case 6920: /* module 27 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V22(c, &method->basic.recovery_cancel_recovered_V22))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V22(c, &method->basic.vesting_vest_V22))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V22(c, &method->basic.vesting_vest_other_V22))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V22(c, &method->basic.vesting_vested_transfer_V22))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V22(c, &method->basic.vesting_force_vested_transfer_V22))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V22(c, &method->basic.vesting_merge_schedules_V22))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V22(c, &method->nested.proxy_proxy_V22))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V22(c, &method->nested.proxy_add_proxy_V22))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V22(c, &method->nested.proxy_remove_proxy_V22))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V22(c, &method->basic.proxy_remove_proxies_V22))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_proxy_create_pure_V22(c, &method->nested.proxy_create_pure_V22))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_pure_V22(c, &method->nested.proxy_kill_pure_V22))
        break;
    case 7689: /* module 30 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V22(c, &method->basic.proxy_proxy_announced_V22))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V22(c, &method->nested.multisig_as_multi_threshold_1_V22))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V22(c, &method->nested.multisig_as_multi_V22))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V22(c, &method->nested.multisig_approve_as_multi_V22))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V22(c, &method->nested.multisig_cancel_as_multi_V22))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V22(c, &method->basic.preimage_note_preimage_V22))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V22(c, &method->basic.preimage_unnote_preimage_V22))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V22(c, &method->basic.preimage_request_preimage_V22))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V22(c, &method->basic.preimage_unrequest_preimage_V22))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V22(c, &method->basic.bounties_propose_bounty_V22))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V22(c, &method->basic.bounties_approve_bounty_V22))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V22(c, &method->basic.bounties_propose_curator_V22))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V22(c, &method->basic.bounties_unassign_curator_V22))
        break;
    case 8964: /* module 35 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V22(c, &method->basic.bounties_accept_curator_V22))
        break;
    case 8965: /* module 35 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V22(c, &method->basic.bounties_award_bounty_V22))
        break;
    case 8966: /* module 35 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V22(c, &method->basic.bounties_claim_bounty_V22))
        break;
    case 8967: /* module 35 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V22(c, &method->basic.bounties_close_bounty_V22))
        break;
    case 8968: /* module 35 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V22(c, &method->basic.bounties_extend_bounty_expiry_V22))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_childbounties_add_child_bounty_V22(c, &method->basic.childbounties_add_child_bounty_V22))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_childbounties_propose_curator_V22(c, &method->basic.childbounties_propose_curator_V22))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_childbounties_accept_curator_V22(c, &method->basic.childbounties_accept_curator_V22))
        break;
    case 10243: /* module 40 call 3 */
        CHECK_ERROR(_readMethod_childbounties_unassign_curator_V22(c, &method->basic.childbounties_unassign_curator_V22))
        break;
    case 10244: /* module 40 call 4 */
        CHECK_ERROR(_readMethod_childbounties_award_child_bounty_V22(c, &method->basic.childbounties_award_child_bounty_V22))
        break;
    case 10245: /* module 40 call 5 */
        CHECK_ERROR(_readMethod_childbounties_claim_child_bounty_V22(c, &method->basic.childbounties_claim_child_bounty_V22))
        break;
    case 10246: /* module 40 call 6 */
        CHECK_ERROR(_readMethod_childbounties_close_child_bounty_V22(c, &method->basic.childbounties_close_child_bounty_V22))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_nis_place_bid_V22(c, &method->basic.nis_place_bid_V22))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_nis_retract_bid_V22(c, &method->basic.nis_retract_bid_V22))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_nis_fund_deficit_V22(c, &method->basic.nis_fund_deficit_V22))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_nis_thaw_private_V22(c, &method->basic.nis_thaw_private_V22))
        break;
    case 9732: /* module 38 call 4 */
        CHECK_ERROR(_readMethod_nis_thaw_communal_V22(c, &method->basic.nis_thaw_communal_V22))
        break;
    case 9733: /* module 38 call 5 */
        CHECK_ERROR(_readMethod_nis_communify_V22(c, &method->basic.nis_communify_V22))
        break;
    case 9734: /* module 38 call 6 */
        CHECK_ERROR(_readMethod_nis_privatize_V22(c, &method->basic.nis_privatize_V22))
        break;
    case 11520: /* module 45 call 0 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_transfer_allow_death_V22(c, &method->basic.niscounterpartbalances_transfer_allow_death_V22))
        break;
    case 11521: /* module 45 call 1 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_set_balance_deprecated_V22(c, &method->basic.niscounterpartbalances_set_balance_deprecated_V22))
        break;
    case 11522: /* module 45 call 2 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_force_transfer_V22(c, &method->basic.niscounterpartbalances_force_transfer_V22))
        break;
    case 11523: /* module 45 call 3 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_transfer_keep_alive_V22(c, &method->basic.niscounterpartbalances_transfer_keep_alive_V22))
        break;
    case 11524: /* module 45 call 4 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_transfer_all_V22(c, &method->basic.niscounterpartbalances_transfer_all_V22))
        break;
    case 11525: /* module 45 call 5 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_force_unreserve_V22(c, &method->basic.niscounterpartbalances_force_unreserve_V22))
        break;
    case 11526: /* module 45 call 6 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_upgrade_accounts_V22(c, &method->basic.niscounterpartbalances_upgrade_accounts_V22))
        break;
    case 11527: /* module 45 call 7 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_transfer_V22(c, &method->basic.niscounterpartbalances_transfer_V22))
        break;
    case 11528: /* module 45 call 8 */
        CHECK_ERROR(_readMethod_niscounterpartbalances_force_set_balance_V22(c, &method->basic.niscounterpartbalances_force_set_balance_V22))
        break;
    case 9984: /* module 39 call 0 */
        CHECK_ERROR(_readMethod_voterlist_rebag_V22(c, &method->basic.voterlist_rebag_V22))
        break;
    case 9985: /* module 39 call 1 */
        CHECK_ERROR(_readMethod_voterlist_put_in_front_of_V22(c, &method->basic.voterlist_put_in_front_of_V22))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_nominationpools_join_V22(c, &method->nested.nominationpools_join_V22))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_nominationpools_bond_extra_V22(c, &method->nested.nominationpools_bond_extra_V22))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_nominationpools_claim_payout_V22(c, &method->nested.nominationpools_claim_payout_V22))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_nominationpools_unbond_V22(c, &method->nested.nominationpools_unbond_V22))
        break;
    case 10500: /* module 41 call 4 */
        CHECK_ERROR(_readMethod_nominationpools_pool_withdraw_unbonded_V22(c, &method->basic.nominationpools_pool_withdraw_unbonded_V22))
        break;
    case 10501: /* module 41 call 5 */
        CHECK_ERROR(_readMethod_nominationpools_withdraw_unbonded_V22(c, &method->nested.nominationpools_withdraw_unbonded_V22))
        break;
    case 10502: /* module 41 call 6 */
        CHECK_ERROR(_readMethod_nominationpools_create_V22(c, &method->nested.nominationpools_create_V22))
        break;
    case 10503: /* module 41 call 7 */
        CHECK_ERROR(_readMethod_nominationpools_create_with_pool_id_V22(c, &method->basic.nominationpools_create_with_pool_id_V22))
        break;
    case 10504: /* module 41 call 8 */
        CHECK_ERROR(_readMethod_nominationpools_nominate_V22(c, &method->nested.nominationpools_nominate_V22))
        break;
    case 10505: /* module 41 call 9 */
        CHECK_ERROR(_readMethod_nominationpools_set_state_V22(c, &method->nested.nominationpools_set_state_V22))
        break;
    case 10506: /* module 41 call 10 */
        CHECK_ERROR(_readMethod_nominationpools_set_metadata_V22(c, &method->nested.nominationpools_set_metadata_V22))
        break;
    case 10507: /* module 41 call 11 */
        CHECK_ERROR(_readMethod_nominationpools_set_configs_V22(c, &method->basic.nominationpools_set_configs_V22))
        break;
    case 10508: /* module 41 call 12 */
        CHECK_ERROR(_readMethod_nominationpools_update_roles_V22(c, &method->nested.nominationpools_update_roles_V22))
        break;
    case 10509: /* module 41 call 13 */
        CHECK_ERROR(_readMethod_nominationpools_chill_V22(c, &method->nested.nominationpools_chill_V22))
        break;
    case 10510: /* module 41 call 14 */
        CHECK_ERROR(_readMethod_nominationpools_bond_extra_other_V22(c, &method->basic.nominationpools_bond_extra_other_V22))
        break;
    case 10511: /* module 41 call 15 */
        CHECK_ERROR(_readMethod_nominationpools_set_claim_permission_V22(c, &method->basic.nominationpools_set_claim_permission_V22))
        break;
    case 10512: /* module 41 call 16 */
        CHECK_ERROR(_readMethod_nominationpools_claim_payout_other_V22(c, &method->basic.nominationpools_claim_payout_other_V22))
        break;
    case 10513: /* module 41 call 17 */
        CHECK_ERROR(_readMethod_nominationpools_set_commission_V22(c, &method->basic.nominationpools_set_commission_V22))
        break;
    case 10514: /* module 41 call 18 */
        CHECK_ERROR(_readMethod_nominationpools_set_commission_max_V22(c, &method->basic.nominationpools_set_commission_max_V22))
        break;
    case 10515: /* module 41 call 19 */
        CHECK_ERROR(_readMethod_nominationpools_set_commission_change_rate_V22(c, &method->basic.nominationpools_set_commission_change_rate_V22))
        break;
    case 10516: /* module 41 call 20 */
        CHECK_ERROR(_readMethod_nominationpools_claim_commission_V22(c, &method->basic.nominationpools_claim_commission_V22))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_fastunstake_register_fast_unstake_V22(c, &method->nested.fastunstake_register_fast_unstake_V22))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_fastunstake_deregister_V22(c, &method->nested.fastunstake_deregister_V22))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_fastunstake_control_V22(c, &method->basic.fastunstake_control_V22))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_cooldown_V22(c, &method->basic.configuration_set_validation_upgrade_cooldown_V22))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_delay_V22(c, &method->basic.configuration_set_validation_upgrade_delay_V22))
        break;
    case 13058: /* module 51 call 2 */
        CHECK_ERROR(_readMethod_configuration_set_code_retention_period_V22(c, &method->basic.configuration_set_code_retention_period_V22))
        break;
    case 13059: /* module 51 call 3 */
        CHECK_ERROR(_readMethod_configuration_set_max_code_size_V22(c, &method->basic.configuration_set_max_code_size_V22))
        break;
    case 13060: /* module 51 call 4 */
        CHECK_ERROR(_readMethod_configuration_set_max_pov_size_V22(c, &method->basic.configuration_set_max_pov_size_V22))
        break;
    case 13061: /* module 51 call 5 */
        CHECK_ERROR(_readMethod_configuration_set_max_head_data_size_V22(c, &method->basic.configuration_set_max_head_data_size_V22))
        break;
    case 13062: /* module 51 call 6 */
        CHECK_ERROR(_readMethod_configuration_set_parathread_cores_V22(c, &method->basic.configuration_set_parathread_cores_V22))
        break;
    case 13063: /* module 51 call 7 */
        CHECK_ERROR(_readMethod_configuration_set_parathread_retries_V22(c, &method->basic.configuration_set_parathread_retries_V22))
        break;
    case 13064: /* module 51 call 8 */
        CHECK_ERROR(_readMethod_configuration_set_group_rotation_frequency_V22(c, &method->basic.configuration_set_group_rotation_frequency_V22))
        break;
    case 13065: /* module 51 call 9 */
        CHECK_ERROR(_readMethod_configuration_set_chain_availability_period_V22(c, &method->basic.configuration_set_chain_availability_period_V22))
        break;
    case 13066: /* module 51 call 10 */
        CHECK_ERROR(_readMethod_configuration_set_thread_availability_period_V22(c, &method->basic.configuration_set_thread_availability_period_V22))
        break;
    case 13067: /* module 51 call 11 */
        CHECK_ERROR(_readMethod_configuration_set_scheduling_lookahead_V22(c, &method->basic.configuration_set_scheduling_lookahead_V22))
        break;
    case 13068: /* module 51 call 12 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_per_core_V22(c, &method->basic.configuration_set_max_validators_per_core_V22))
        break;
    case 13069: /* module 51 call 13 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_V22(c, &method->basic.configuration_set_max_validators_V22))
        break;
    case 13070: /* module 51 call 14 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_period_V22(c, &method->basic.configuration_set_dispute_period_V22))
        break;
    case 13071: /* module 51 call 15 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V22(c, &method->basic.configuration_set_dispute_post_conclusion_acceptance_period_V22))
        break;
    case 13074: /* module 51 call 18 */
        CHECK_ERROR(_readMethod_configuration_set_no_show_slots_V22(c, &method->basic.configuration_set_no_show_slots_V22))
        break;
    case 13075: /* module 51 call 19 */
        CHECK_ERROR(_readMethod_configuration_set_n_delay_tranches_V22(c, &method->basic.configuration_set_n_delay_tranches_V22))
        break;
    case 13076: /* module 51 call 20 */
        CHECK_ERROR(_readMethod_configuration_set_zeroth_delay_tranche_width_V22(c, &method->basic.configuration_set_zeroth_delay_tranche_width_V22))
        break;
    case 13077: /* module 51 call 21 */
        CHECK_ERROR(_readMethod_configuration_set_needed_approvals_V22(c, &method->basic.configuration_set_needed_approvals_V22))
        break;
    case 13078: /* module 51 call 22 */
        CHECK_ERROR(_readMethod_configuration_set_relay_vrf_modulo_samples_V22(c, &method->basic.configuration_set_relay_vrf_modulo_samples_V22))
        break;
    case 13079: /* module 51 call 23 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_count_V22(c, &method->basic.configuration_set_max_upward_queue_count_V22))
        break;
    case 13080: /* module 51 call 24 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_size_V22(c, &method->basic.configuration_set_max_upward_queue_size_V22))
        break;
    case 13081: /* module 51 call 25 */
        CHECK_ERROR(_readMethod_configuration_set_max_downward_message_size_V22(c, &method->basic.configuration_set_max_downward_message_size_V22))
        break;
    case 13082: /* module 51 call 26 */
        CHECK_ERROR(_readMethod_configuration_set_ump_service_total_weight_V22(c, &method->basic.configuration_set_ump_service_total_weight_V22))
        break;
    case 13083: /* module 51 call 27 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_size_V22(c, &method->basic.configuration_set_max_upward_message_size_V22))
        break;
    case 13084: /* module 51 call 28 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_num_per_candidate_V22(c, &method->basic.configuration_set_max_upward_message_num_per_candidate_V22))
        break;
    case 13085: /* module 51 call 29 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_open_request_ttl_V22(c, &method->basic.configuration_set_hrmp_open_request_ttl_V22))
        break;
    case 13086: /* module 51 call 30 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_sender_deposit_V22(c, &method->basic.configuration_set_hrmp_sender_deposit_V22))
        break;
    case 13087: /* module 51 call 31 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_recipient_deposit_V22(c, &method->basic.configuration_set_hrmp_recipient_deposit_V22))
        break;
    case 13088: /* module 51 call 32 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_capacity_V22(c, &method->basic.configuration_set_hrmp_channel_max_capacity_V22))
        break;
    case 13089: /* module 51 call 33 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_total_size_V22(c, &method->basic.configuration_set_hrmp_channel_max_total_size_V22))
        break;
    case 13090: /* module 51 call 34 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V22(c, &method->basic.configuration_set_hrmp_max_parachain_inbound_channels_V22))
        break;
    case 13091: /* module 51 call 35 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parathread_inbound_channels_V22(c, &method->basic.configuration_set_hrmp_max_parathread_inbound_channels_V22))
        break;
    case 13092: /* module 51 call 36 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_message_size_V22(c, &method->basic.configuration_set_hrmp_channel_max_message_size_V22))
        break;
    case 13093: /* module 51 call 37 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V22(c, &method->basic.configuration_set_hrmp_max_parachain_outbound_channels_V22))
        break;
    case 13094: /* module 51 call 38 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parathread_outbound_channels_V22(c, &method->basic.configuration_set_hrmp_max_parathread_outbound_channels_V22))
        break;
    case 13095: /* module 51 call 39 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_message_num_per_candidate_V22(c, &method->basic.configuration_set_hrmp_max_message_num_per_candidate_V22))
        break;
    case 13096: /* module 51 call 40 */
        CHECK_ERROR(_readMethod_configuration_set_ump_max_individual_weight_V22(c, &method->basic.configuration_set_ump_max_individual_weight_V22))
        break;
    case 13097: /* module 51 call 41 */
        CHECK_ERROR(_readMethod_configuration_set_pvf_checking_enabled_V22(c, &method->basic.configuration_set_pvf_checking_enabled_V22))
        break;
    case 13098: /* module 51 call 42 */
        CHECK_ERROR(_readMethod_configuration_set_pvf_voting_ttl_V22(c, &method->basic.configuration_set_pvf_voting_ttl_V22))
        break;
    case 13099: /* module 51 call 43 */
        CHECK_ERROR(_readMethod_configuration_set_minimum_validation_upgrade_delay_V22(c, &method->basic.configuration_set_minimum_validation_upgrade_delay_V22))
        break;
    case 13100: /* module 51 call 44 */
        CHECK_ERROR(_readMethod_configuration_set_bypass_consistency_check_V22(c, &method->basic.configuration_set_bypass_consistency_check_V22))
        break;
    case 14592: /* module 57 call 0 */
        CHECK_ERROR(_readMethod_initializer_force_approve_V22(c, &method->basic.initializer_force_approve_V22))
        break;
    case 15104: /* module 59 call 0 */
        CHECK_ERROR(_readMethod_ump_service_overweight_V22(c, &method->basic.ump_service_overweight_V22))
        break;
    case 15872: /* module 62 call 0 */
        CHECK_ERROR(_readMethod_parasdisputes_force_unfreeze_V22(c, &method->basic.parasdisputes_force_unfreeze_V22))
        break;
    case 18432: /* module 72 call 0 */
        CHECK_ERROR(_readMethod_auctions_new_auction_V22(c, &method->basic.auctions_new_auction_V22))
        break;
    case 18433: /* module 72 call 1 */
        CHECK_ERROR(_readMethod_auctions_bid_V22(c, &method->basic.auctions_bid_V22))
        break;
    case 18434: /* module 72 call 2 */
        CHECK_ERROR(_readMethod_auctions_cancel_auction_V22(c, &method->basic.auctions_cancel_auction_V22))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V22(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 4:
        return STR_MO_BALANCES;
    case 6:
        return STR_MO_STAKING;
    case 8:
        return STR_MO_SESSION;
    case 24:
        return STR_MO_UTILITY;
    case 73:
        return STR_MO_CROWDLOAN;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 99:
        return STR_MO_XCMPALLET;
#endif
    case 0:
        return STR_MO_SYSTEM;
    case 2:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_INDICES;
    case 18:
        return STR_MO_TREASURY;
    case 20:
        return STR_MO_CONVICTIONVOTING;
    case 21:
        return STR_MO_REFERENDA;
    case 22:
        return STR_MO_FELLOWSHIPCOLLECTIVE;
    case 23:
        return STR_MO_FELLOWSHIPREFERENDA;
    case 44:
        return STR_MO_WHITELIST;
    case 19:
        return STR_MO_CLAIMS;
    case 25:
        return STR_MO_IDENTITY;
    case 26:
        return STR_MO_SOCIETY;
    case 27:
        return STR_MO_RECOVERY;
    case 28:
        return STR_MO_VESTING;
    case 30:
        return STR_MO_PROXY;
    case 31:
        return STR_MO_MULTISIG;
    case 32:
        return STR_MO_PREIMAGE;
    case 35:
        return STR_MO_BOUNTIES;
    case 40:
        return STR_MO_CHILDBOUNTIES;
    case 38:
        return STR_MO_NIS;
    case 45:
        return STR_MO_NISCOUNTERPARTBALANCES;
    case 39:
        return STR_MO_VOTERLIST;
    case 41:
        return STR_MO_NOMINATIONPOOLS;
    case 42:
        return STR_MO_FASTUNSTAKE;
    case 51:
        return STR_MO_CONFIGURATION;
    case 57:
        return STR_MO_INITIALIZER;
    case 59:
        return STR_MO_UMP;
    case 62:
        return STR_MO_PARASDISPUTES;
    case 72:
        return STR_MO_AUCTIONS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V22(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 1026: /* module 4 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1027: /* module 4 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1028: /* module 4 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 1031: /* module 4 call 7 */
        return STR_ME_TRANSFER;
    case 1536: /* module 6 call 0 */
        return STR_ME_BOND;
    case 1537: /* module 6 call 1 */
        return STR_ME_BOND_EXTRA;
    case 1538: /* module 6 call 2 */
        return STR_ME_UNBOND;
    case 1539: /* module 6 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 1540: /* module 6 call 4 */
        return STR_ME_VALIDATE;
    case 1541: /* module 6 call 5 */
        return STR_ME_NOMINATE;
    case 1542: /* module 6 call 6 */
        return STR_ME_CHILL;
    case 1543: /* module 6 call 7 */
        return STR_ME_SET_PAYEE;
    case 1544: /* module 6 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 1554: /* module 6 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 1555: /* module 6 call 19 */
        return STR_ME_REBOND;
    case 2048: /* module 8 call 0 */
        return STR_ME_SET_KEYS;
    case 2049: /* module 8 call 1 */
        return STR_ME_PURGE_KEYS;
    case 6144: /* module 24 call 0 */
        return STR_ME_BATCH;
    case 6146: /* module 24 call 2 */
        return STR_ME_BATCH_ALL;
    case 6148: /* module 24 call 4 */
        return STR_ME_FORCE_BATCH;
    case 18688: /* module 73 call 0 */
        return STR_ME_CREATE;
    case 18689: /* module 73 call 1 */
        return STR_ME_CONTRIBUTE;
    case 18690: /* module 73 call 2 */
        return STR_ME_WITHDRAW;
    case 18691: /* module 73 call 3 */
        return STR_ME_REFUND;
    case 18692: /* module 73 call 4 */
        return STR_ME_DISSOLVE;
    case 18693: /* module 73 call 5 */
        return STR_ME_EDIT;
    case 18694: /* module 73 call 6 */
        return STR_ME_ADD_MEMO;
    case 18695: /* module 73 call 7 */
        return STR_ME_POKE;
    case 18696: /* module 73 call 8 */
        return STR_ME_CONTRIBUTE_ALL;
    default:
        return _getMethod_Name_V22_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V22_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        return STR_ME_TELEPORT_ASSETS;
    case 25346: /* module 99 call 2 */
        return STR_ME_RESERVE_TRANSFER_ASSETS;
    case 25352: /* module 99 call 8 */
        return STR_ME_LIMITED_RESERVE_TRANSFER_ASSETS;
    case 25353: /* module 99 call 9 */
        return STR_ME_LIMITED_TELEPORT_ASSETS;
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_REMARK;
    case 1: /* module 0 call 1 */
        return STR_ME_SET_HEAP_PAGES;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_CODE;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 7: /* module 0 call 7 */
        return STR_ME_REMARK_WITH_EVENT;
    case 512: /* module 2 call 0 */
        return STR_ME_SET;
    case 768: /* module 3 call 0 */
        return STR_ME_CLAIM;
    case 769: /* module 3 call 1 */
        return STR_ME_TRANSFER;
    case 770: /* module 3 call 2 */
        return STR_ME_FREE;
    case 771: /* module 3 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 772: /* module 3 call 4 */
        return STR_ME_FREEZE;
    case 1025: /* module 4 call 1 */
        return STR_ME_SET_BALANCE_DEPRECATED;
    case 1029: /* module 4 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1030: /* module 4 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 1032: /* module 4 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
    case 1545: /* module 6 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 1546: /* module 6 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 1547: /* module 6 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 1548: /* module 6 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 1549: /* module 6 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 1550: /* module 6 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 1551: /* module 6 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 1552: /* module 6 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 1553: /* module 6 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 1556: /* module 6 call 20 */
        return STR_ME_REAP_STASH;
    case 1557: /* module 6 call 21 */
        return STR_ME_KICK;
    case 1558: /* module 6 call 22 */
        return STR_ME_SET_STAKING_CONFIGS;
    case 1559: /* module 6 call 23 */
        return STR_ME_CHILL_OTHER;
    case 1560: /* module 6 call 24 */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
    case 1561: /* module 6 call 25 */
        return STR_ME_SET_MIN_COMMISSION;
    case 4608: /* module 18 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4609: /* module 18 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4610: /* module 18 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4611: /* module 18 call 3 */
        return STR_ME_SPEND;
    case 4612: /* module 18 call 4 */
        return STR_ME_REMOVE_APPROVAL;
    case 5120: /* module 20 call 0 */
        return STR_ME_VOTE;
    case 5121: /* module 20 call 1 */
        return STR_ME_DELEGATE;
    case 5122: /* module 20 call 2 */
        return STR_ME_UNDELEGATE;
    case 5123: /* module 20 call 3 */
        return STR_ME_UNLOCK;
    case 5124: /* module 20 call 4 */
        return STR_ME_REMOVE_VOTE;
    case 5125: /* module 20 call 5 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 5377: /* module 21 call 1 */
        return STR_ME_PLACE_DECISION_DEPOSIT;
    case 5378: /* module 21 call 2 */
        return STR_ME_REFUND_DECISION_DEPOSIT;
    case 5379: /* module 21 call 3 */
        return STR_ME_CANCEL;
    case 5380: /* module 21 call 4 */
        return STR_ME_KILL;
    case 5381: /* module 21 call 5 */
        return STR_ME_NUDGE_REFERENDUM;
    case 5382: /* module 21 call 6 */
        return STR_ME_ONE_FEWER_DECIDING;
    case 5383: /* module 21 call 7 */
        return STR_ME_REFUND_SUBMISSION_DEPOSIT;
    case 5384: /* module 21 call 8 */
        return STR_ME_SET_METADATA;
    case 5632: /* module 22 call 0 */
        return STR_ME_ADD_MEMBER;
    case 5633: /* module 22 call 1 */
        return STR_ME_PROMOTE_MEMBER;
    case 5634: /* module 22 call 2 */
        return STR_ME_DEMOTE_MEMBER;
    case 5635: /* module 22 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 5636: /* module 22 call 4 */
        return STR_ME_VOTE;
    case 5637: /* module 22 call 5 */
        return STR_ME_CLEANUP_POLL;
    case 5889: /* module 23 call 1 */
        return STR_ME_PLACE_DECISION_DEPOSIT;
    case 5890: /* module 23 call 2 */
        return STR_ME_REFUND_DECISION_DEPOSIT;
    case 5891: /* module 23 call 3 */
        return STR_ME_CANCEL;
    case 5892: /* module 23 call 4 */
        return STR_ME_KILL;
    case 5893: /* module 23 call 5 */
        return STR_ME_NUDGE_REFERENDUM;
    case 5894: /* module 23 call 6 */
        return STR_ME_ONE_FEWER_DECIDING;
    case 5895: /* module 23 call 7 */
        return STR_ME_REFUND_SUBMISSION_DEPOSIT;
    case 5896: /* module 23 call 8 */
        return STR_ME_SET_METADATA;
    case 11264: /* module 44 call 0 */
        return STR_ME_WHITELIST_CALL;
    case 11265: /* module 44 call 1 */
        return STR_ME_REMOVE_WHITELISTED_CALL;
    case 11266: /* module 44 call 2 */
        return STR_ME_DISPATCH_WHITELISTED_CALL;
    case 11267: /* module 44 call 3 */
        return STR_ME_DISPATCH_WHITELISTED_CALL_WITH_PREIMAGE;
    case 4864: /* module 19 call 0 */
        return STR_ME_CLAIM;
    case 4866: /* module 19 call 2 */
        return STR_ME_CLAIM_ATTEST;
    case 4867: /* module 19 call 3 */
        return STR_ME_ATTEST;
    case 4868: /* module 19 call 4 */
        return STR_ME_MOVE_CLAIM;
    case 6149: /* module 24 call 5 */
        return STR_ME_WITH_WEIGHT;
    case 6400: /* module 25 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 6401: /* module 25 call 1 */
        return STR_ME_SET_IDENTITY;
    case 6402: /* module 25 call 2 */
        return STR_ME_SET_SUBS;
    case 6403: /* module 25 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 6404: /* module 25 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 6405: /* module 25 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 6406: /* module 25 call 6 */
        return STR_ME_SET_FEE;
    case 6407: /* module 25 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 6409: /* module 25 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 6410: /* module 25 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 6411: /* module 25 call 11 */
        return STR_ME_ADD_SUB;
    case 6412: /* module 25 call 12 */
        return STR_ME_RENAME_SUB;
    case 6413: /* module 25 call 13 */
        return STR_ME_REMOVE_SUB;
    case 6414: /* module 25 call 14 */
        return STR_ME_QUIT_SUB;
    case 6656: /* module 26 call 0 */
        return STR_ME_BID;
    case 6657: /* module 26 call 1 */
        return STR_ME_UNBID;
    case 6658: /* module 26 call 2 */
        return STR_ME_VOUCH;
    case 6659: /* module 26 call 3 */
        return STR_ME_UNVOUCH;
    case 6660: /* module 26 call 4 */
        return STR_ME_VOTE;
    case 6661: /* module 26 call 5 */
        return STR_ME_DEFENDER_VOTE;
    case 6662: /* module 26 call 6 */
        return STR_ME_PAYOUT;
    case 6663: /* module 26 call 7 */
        return STR_ME_FOUND;
    case 6664: /* module 26 call 8 */
        return STR_ME_UNFOUND;
    case 6665: /* module 26 call 9 */
        return STR_ME_JUDGE_SUSPENDED_MEMBER;
    case 6667: /* module 26 call 11 */
        return STR_ME_SET_MAX_MEMBERS;
    case 6913: /* module 27 call 1 */
        return STR_ME_SET_RECOVERED;
    case 6915: /* module 27 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 6916: /* module 27 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 6917: /* module 27 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 6918: /* module 27 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 6919: /* module 27 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 6920: /* module 27 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 7168: /* module 28 call 0 */
        return STR_ME_VEST;
    case 7169: /* module 28 call 1 */
        return STR_ME_VEST_OTHER;
    case 7170: /* module 28 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 7171: /* module 28 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 7172: /* module 28 call 4 */
        return STR_ME_MERGE_SCHEDULES;
    case 7680: /* module 30 call 0 */
        return STR_ME_PROXY;
    case 7681: /* module 30 call 1 */
        return STR_ME_ADD_PROXY;
    case 7682: /* module 30 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 7683: /* module 30 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 7684: /* module 30 call 4 */
        return STR_ME_CREATE_PURE;
    case 7685: /* module 30 call 5 */
        return STR_ME_KILL_PURE;
    case 7689: /* module 30 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7936: /* module 31 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7937: /* module 31 call 1 */
        return STR_ME_AS_MULTI;
    case 7938: /* module 31 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7939: /* module 31 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 8192: /* module 32 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 8193: /* module 32 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 8194: /* module 32 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 8195: /* module 32 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 8960: /* module 35 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 8961: /* module 35 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 8962: /* module 35 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 8963: /* module 35 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 8964: /* module 35 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 8965: /* module 35 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 8966: /* module 35 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 8967: /* module 35 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 8968: /* module 35 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 10240: /* module 40 call 0 */
        return STR_ME_ADD_CHILD_BOUNTY;
    case 10241: /* module 40 call 1 */
        return STR_ME_PROPOSE_CURATOR;
    case 10242: /* module 40 call 2 */
        return STR_ME_ACCEPT_CURATOR;
    case 10243: /* module 40 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 10244: /* module 40 call 4 */
        return STR_ME_AWARD_CHILD_BOUNTY;
    case 10245: /* module 40 call 5 */
        return STR_ME_CLAIM_CHILD_BOUNTY;
    case 10246: /* module 40 call 6 */
        return STR_ME_CLOSE_CHILD_BOUNTY;
    case 9728: /* module 38 call 0 */
        return STR_ME_PLACE_BID;
    case 9729: /* module 38 call 1 */
        return STR_ME_RETRACT_BID;
    case 9730: /* module 38 call 2 */
        return STR_ME_FUND_DEFICIT;
    case 9731: /* module 38 call 3 */
        return STR_ME_THAW_PRIVATE;
    case 9732: /* module 38 call 4 */
        return STR_ME_THAW_COMMUNAL;
    case 9733: /* module 38 call 5 */
        return STR_ME_COMMUNIFY;
    case 9734: /* module 38 call 6 */
        return STR_ME_PRIVATIZE;
    case 11520: /* module 45 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 11521: /* module 45 call 1 */
        return STR_ME_SET_BALANCE_DEPRECATED;
    case 11522: /* module 45 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 11523: /* module 45 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 11524: /* module 45 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 11525: /* module 45 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 11526: /* module 45 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 11527: /* module 45 call 7 */
        return STR_ME_TRANSFER;
    case 11528: /* module 45 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
    case 9984: /* module 39 call 0 */
        return STR_ME_REBAG;
    case 9985: /* module 39 call 1 */
        return STR_ME_PUT_IN_FRONT_OF;
    case 10496: /* module 41 call 0 */
        return STR_ME_JOIN;
    case 10497: /* module 41 call 1 */
        return STR_ME_BOND_EXTRA;
    case 10498: /* module 41 call 2 */
        return STR_ME_CLAIM_PAYOUT;
    case 10499: /* module 41 call 3 */
        return STR_ME_UNBOND;
    case 10500: /* module 41 call 4 */
        return STR_ME_POOL_WITHDRAW_UNBONDED;
    case 10501: /* module 41 call 5 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 10502: /* module 41 call 6 */
        return STR_ME_CREATE;
    case 10503: /* module 41 call 7 */
        return STR_ME_CREATE_WITH_POOL_ID;
    case 10504: /* module 41 call 8 */
        return STR_ME_NOMINATE;
    case 10505: /* module 41 call 9 */
        return STR_ME_SET_STATE;
    case 10506: /* module 41 call 10 */
        return STR_ME_SET_METADATA;
    case 10507: /* module 41 call 11 */
        return STR_ME_SET_CONFIGS;
    case 10508: /* module 41 call 12 */
        return STR_ME_UPDATE_ROLES;
    case 10509: /* module 41 call 13 */
        return STR_ME_CHILL;
    case 10510: /* module 41 call 14 */
        return STR_ME_BOND_EXTRA_OTHER;
    case 10511: /* module 41 call 15 */
        return STR_ME_SET_CLAIM_PERMISSION;
    case 10512: /* module 41 call 16 */
        return STR_ME_CLAIM_PAYOUT_OTHER;
    case 10513: /* module 41 call 17 */
        return STR_ME_SET_COMMISSION;
    case 10514: /* module 41 call 18 */
        return STR_ME_SET_COMMISSION_MAX;
    case 10515: /* module 41 call 19 */
        return STR_ME_SET_COMMISSION_CHANGE_RATE;
    case 10516: /* module 41 call 20 */
        return STR_ME_CLAIM_COMMISSION;
    case 10752: /* module 42 call 0 */
        return STR_ME_REGISTER_FAST_UNSTAKE;
    case 10753: /* module 42 call 1 */
        return STR_ME_DEREGISTER;
    case 10754: /* module 42 call 2 */
        return STR_ME_CONTROL;
    case 13056: /* module 51 call 0 */
        return STR_ME_SET_VALIDATION_UPGRADE_COOLDOWN;
    case 13057: /* module 51 call 1 */
        return STR_ME_SET_VALIDATION_UPGRADE_DELAY;
    case 13058: /* module 51 call 2 */
        return STR_ME_SET_CODE_RETENTION_PERIOD;
    case 13059: /* module 51 call 3 */
        return STR_ME_SET_MAX_CODE_SIZE;
    case 13060: /* module 51 call 4 */
        return STR_ME_SET_MAX_POV_SIZE;
    case 13061: /* module 51 call 5 */
        return STR_ME_SET_MAX_HEAD_DATA_SIZE;
    case 13062: /* module 51 call 6 */
        return STR_ME_SET_PARATHREAD_CORES;
    case 13063: /* module 51 call 7 */
        return STR_ME_SET_PARATHREAD_RETRIES;
    case 13064: /* module 51 call 8 */
        return STR_ME_SET_GROUP_ROTATION_FREQUENCY;
    case 13065: /* module 51 call 9 */
        return STR_ME_SET_CHAIN_AVAILABILITY_PERIOD;
    case 13066: /* module 51 call 10 */
        return STR_ME_SET_THREAD_AVAILABILITY_PERIOD;
    case 13067: /* module 51 call 11 */
        return STR_ME_SET_SCHEDULING_LOOKAHEAD;
    case 13068: /* module 51 call 12 */
        return STR_ME_SET_MAX_VALIDATORS_PER_CORE;
    case 13069: /* module 51 call 13 */
        return STR_ME_SET_MAX_VALIDATORS;
    case 13070: /* module 51 call 14 */
        return STR_ME_SET_DISPUTE_PERIOD;
    case 13071: /* module 51 call 15 */
        return STR_ME_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD;
    case 13074: /* module 51 call 18 */
        return STR_ME_SET_NO_SHOW_SLOTS;
    case 13075: /* module 51 call 19 */
        return STR_ME_SET_N_DELAY_TRANCHES;
    case 13076: /* module 51 call 20 */
        return STR_ME_SET_ZEROTH_DELAY_TRANCHE_WIDTH;
    case 13077: /* module 51 call 21 */
        return STR_ME_SET_NEEDED_APPROVALS;
    case 13078: /* module 51 call 22 */
        return STR_ME_SET_RELAY_VRF_MODULO_SAMPLES;
    case 13079: /* module 51 call 23 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_COUNT;
    case 13080: /* module 51 call 24 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_SIZE;
    case 13081: /* module 51 call 25 */
        return STR_ME_SET_MAX_DOWNWARD_MESSAGE_SIZE;
    case 13082: /* module 51 call 26 */
        return STR_ME_SET_UMP_SERVICE_TOTAL_WEIGHT;
    case 13083: /* module 51 call 27 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_SIZE;
    case 13084: /* module 51 call 28 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE;
    case 13085: /* module 51 call 29 */
        return STR_ME_SET_HRMP_OPEN_REQUEST_TTL;
    case 13086: /* module 51 call 30 */
        return STR_ME_SET_HRMP_SENDER_DEPOSIT;
    case 13087: /* module 51 call 31 */
        return STR_ME_SET_HRMP_RECIPIENT_DEPOSIT;
    case 13088: /* module 51 call 32 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_CAPACITY;
    case 13089: /* module 51 call 33 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE;
    case 13090: /* module 51 call 34 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS;
    case 13091: /* module 51 call 35 */
        return STR_ME_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS;
    case 13092: /* module 51 call 36 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE;
    case 13093: /* module 51 call 37 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS;
    case 13094: /* module 51 call 38 */
        return STR_ME_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS;
    case 13095: /* module 51 call 39 */
        return STR_ME_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE;
    case 13096: /* module 51 call 40 */
        return STR_ME_SET_UMP_MAX_INDIVIDUAL_WEIGHT;
    case 13097: /* module 51 call 41 */
        return STR_ME_SET_PVF_CHECKING_ENABLED;
    case 13098: /* module 51 call 42 */
        return STR_ME_SET_PVF_VOTING_TTL;
    case 13099: /* module 51 call 43 */
        return STR_ME_SET_MINIMUM_VALIDATION_UPGRADE_DELAY;
    case 13100: /* module 51 call 44 */
        return STR_ME_SET_BYPASS_CONSISTENCY_CHECK;
    case 14592: /* module 57 call 0 */
        return STR_ME_FORCE_APPROVE;
    case 15104: /* module 59 call 0 */
        return STR_ME_SERVICE_OVERWEIGHT;
    case 15872: /* module 62 call 0 */
        return STR_ME_FORCE_UNFREEZE;
    case 18432: /* module 72 call 0 */
        return STR_ME_NEW_AUCTION;
    case 18433: /* module 72 call 1 */
        return STR_ME_BID;
    case 18434: /* module 72 call 2 */
        return STR_ME_CANCEL_AUCTION;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V22(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1027: /* module 4 call 3 */
        return 2;
    case 1028: /* module 4 call 4 */
        return 2;
    case 1031: /* module 4 call 7 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 3;
    case 1537: /* module 6 call 1 */
        return 1;
    case 1538: /* module 6 call 2 */
        return 1;
    case 1539: /* module 6 call 3 */
        return 1;
    case 1540: /* module 6 call 4 */
        return 1;
    case 1541: /* module 6 call 5 */
        return 1;
    case 1542: /* module 6 call 6 */
        return 0;
    case 1543: /* module 6 call 7 */
        return 1;
    case 1544: /* module 6 call 8 */
        return 1;
    case 1554: /* module 6 call 18 */
        return 2;
    case 1555: /* module 6 call 19 */
        return 1;
    case 2048: /* module 8 call 0 */
        return 2;
    case 2049: /* module 8 call 1 */
        return 0;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6146: /* module 24 call 2 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 1;
    case 18688: /* module 73 call 0 */
        return 6;
    case 18689: /* module 73 call 1 */
        return 3;
    case 18690: /* module 73 call 2 */
        return 2;
    case 18691: /* module 73 call 3 */
        return 1;
    case 18692: /* module 73 call 4 */
        return 1;
    case 18693: /* module 73 call 5 */
        return 6;
    case 18694: /* module 73 call 6 */
        return 2;
    case 18695: /* module 73 call 7 */
        return 1;
    case 18696: /* module 73 call 8 */
        return 2;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        return 4;
    case 25346: /* module 99 call 2 */
        return 4;
    case 25352: /* module 99 call 8 */
        return 5;
    case 25353: /* module 99 call 9 */
        return 5;
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 512: /* module 2 call 0 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 769: /* module 3 call 1 */
        return 2;
    case 770: /* module 3 call 2 */
        return 1;
    case 771: /* module 3 call 3 */
        return 3;
    case 772: /* module 3 call 4 */
        return 1;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1029: /* module 4 call 5 */
        return 2;
    case 1030: /* module 4 call 6 */
        return 1;
    case 1032: /* module 4 call 8 */
        return 2;
    case 1545: /* module 6 call 9 */
        return 1;
    case 1546: /* module 6 call 10 */
        return 1;
    case 1547: /* module 6 call 11 */
        return 1;
    case 1548: /* module 6 call 12 */
        return 0;
    case 1549: /* module 6 call 13 */
        return 0;
    case 1550: /* module 6 call 14 */
        return 1;
    case 1551: /* module 6 call 15 */
        return 2;
    case 1552: /* module 6 call 16 */
        return 0;
    case 1553: /* module 6 call 17 */
        return 2;
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 1;
    case 1558: /* module 6 call 22 */
        return 6;
    case 1559: /* module 6 call 23 */
        return 1;
    case 1560: /* module 6 call 24 */
        return 1;
    case 1561: /* module 6 call 25 */
        return 1;
    case 4608: /* module 18 call 0 */
        return 2;
    case 4609: /* module 18 call 1 */
        return 1;
    case 4610: /* module 18 call 2 */
        return 1;
    case 4611: /* module 18 call 3 */
        return 2;
    case 4612: /* module 18 call 4 */
        return 1;
    case 5120: /* module 20 call 0 */
        return 2;
    case 5121: /* module 20 call 1 */
        return 4;
    case 5122: /* module 20 call 2 */
        return 1;
    case 5123: /* module 20 call 3 */
        return 2;
    case 5124: /* module 20 call 4 */
        return 2;
    case 5125: /* module 20 call 5 */
        return 3;
    case 5377: /* module 21 call 1 */
        return 1;
    case 5378: /* module 21 call 2 */
        return 1;
    case 5379: /* module 21 call 3 */
        return 1;
    case 5380: /* module 21 call 4 */
        return 1;
    case 5381: /* module 21 call 5 */
        return 1;
    case 5382: /* module 21 call 6 */
        return 1;
    case 5383: /* module 21 call 7 */
        return 1;
    case 5384: /* module 21 call 8 */
        return 2;
    case 5632: /* module 22 call 0 */
        return 1;
    case 5633: /* module 22 call 1 */
        return 1;
    case 5634: /* module 22 call 2 */
        return 1;
    case 5635: /* module 22 call 3 */
        return 2;
    case 5636: /* module 22 call 4 */
        return 2;
    case 5637: /* module 22 call 5 */
        return 2;
    case 5889: /* module 23 call 1 */
        return 1;
    case 5890: /* module 23 call 2 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 1;
    case 5892: /* module 23 call 4 */
        return 1;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 1;
    case 5895: /* module 23 call 7 */
        return 1;
    case 5896: /* module 23 call 8 */
        return 2;
    case 11264: /* module 44 call 0 */
        return 1;
    case 11265: /* module 44 call 1 */
        return 1;
    case 11266: /* module 44 call 2 */
        return 3;
    case 11267: /* module 44 call 3 */
        return 1;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4866: /* module 19 call 2 */
        return 3;
    case 4867: /* module 19 call 3 */
        return 1;
    case 4868: /* module 19 call 4 */
        return 3;
    case 6149: /* module 24 call 5 */
        return 2;
    case 6400: /* module 25 call 0 */
        return 1;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 1;
    case 6403: /* module 25 call 3 */
        return 0;
    case 6404: /* module 25 call 4 */
        return 2;
    case 6405: /* module 25 call 5 */
        return 1;
    case 6406: /* module 25 call 6 */
        return 2;
    case 6407: /* module 25 call 7 */
        return 2;
    case 6409: /* module 25 call 9 */
        return 4;
    case 6410: /* module 25 call 10 */
        return 1;
    case 6411: /* module 25 call 11 */
        return 2;
    case 6412: /* module 25 call 12 */
        return 2;
    case 6413: /* module 25 call 13 */
        return 1;
    case 6414: /* module 25 call 14 */
        return 0;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 3;
    case 6659: /* module 26 call 3 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 2;
    case 6661: /* module 26 call 5 */
        return 1;
    case 6662: /* module 26 call 6 */
        return 0;
    case 6663: /* module 26 call 7 */
        return 3;
    case 6664: /* module 26 call 8 */
        return 0;
    case 6665: /* module 26 call 9 */
        return 2;
    case 6667: /* module 26 call 11 */
        return 1;
    case 6913: /* module 27 call 1 */
        return 2;
    case 6915: /* module 27 call 3 */
        return 1;
    case 6916: /* module 27 call 4 */
        return 2;
    case 6917: /* module 27 call 5 */
        return 1;
    case 6918: /* module 27 call 6 */
        return 1;
    case 6919: /* module 27 call 7 */
        return 0;
    case 6920: /* module 27 call 8 */
        return 1;
    case 7168: /* module 28 call 0 */
        return 0;
    case 7169: /* module 28 call 1 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 2;
    case 7171: /* module 28 call 3 */
        return 3;
    case 7172: /* module 28 call 4 */
        return 2;
    case 7680: /* module 30 call 0 */
        return 3;
    case 7681: /* module 30 call 1 */
        return 3;
    case 7682: /* module 30 call 2 */
        return 3;
    case 7683: /* module 30 call 3 */
        return 0;
    case 7684: /* module 30 call 4 */
        return 3;
    case 7685: /* module 30 call 5 */
        return 5;
    case 7689: /* module 30 call 9 */
        return 4;
    case 7936: /* module 31 call 0 */
        return 2;
    case 7937: /* module 31 call 1 */
        return 5;
    case 7938: /* module 31 call 2 */
        return 5;
    case 7939: /* module 31 call 3 */
        return 4;
    case 8192: /* module 32 call 0 */
        return 1;
    case 8193: /* module 32 call 1 */
        return 1;
    case 8194: /* module 32 call 2 */
        return 1;
    case 8195: /* module 32 call 3 */
        return 1;
    case 8960: /* module 35 call 0 */
        return 2;
    case 8961: /* module 35 call 1 */
        return 1;
    case 8962: /* module 35 call 2 */
        return 3;
    case 8963: /* module 35 call 3 */
        return 1;
    case 8964: /* module 35 call 4 */
        return 1;
    case 8965: /* module 35 call 5 */
        return 2;
    case 8966: /* module 35 call 6 */
        return 1;
    case 8967: /* module 35 call 7 */
        return 1;
    case 8968: /* module 35 call 8 */
        return 2;
    case 10240: /* module 40 call 0 */
        return 3;
    case 10241: /* module 40 call 1 */
        return 4;
    case 10242: /* module 40 call 2 */
        return 2;
    case 10243: /* module 40 call 3 */
        return 2;
    case 10244: /* module 40 call 4 */
        return 3;
    case 10245: /* module 40 call 5 */
        return 2;
    case 10246: /* module 40 call 6 */
        return 2;
    case 9728: /* module 38 call 0 */
        return 2;
    case 9729: /* module 38 call 1 */
        return 2;
    case 9730: /* module 38 call 2 */
        return 0;
    case 9731: /* module 38 call 3 */
        return 2;
    case 9732: /* module 38 call 4 */
        return 1;
    case 9733: /* module 38 call 5 */
        return 1;
    case 9734: /* module 38 call 6 */
        return 1;
    case 11520: /* module 45 call 0 */
        return 2;
    case 11521: /* module 45 call 1 */
        return 3;
    case 11522: /* module 45 call 2 */
        return 3;
    case 11523: /* module 45 call 3 */
        return 2;
    case 11524: /* module 45 call 4 */
        return 2;
    case 11525: /* module 45 call 5 */
        return 2;
    case 11526: /* module 45 call 6 */
        return 1;
    case 11527: /* module 45 call 7 */
        return 2;
    case 11528: /* module 45 call 8 */
        return 2;
    case 9984: /* module 39 call 0 */
        return 1;
    case 9985: /* module 39 call 1 */
        return 1;
    case 10496: /* module 41 call 0 */
        return 2;
    case 10497: /* module 41 call 1 */
        return 1;
    case 10498: /* module 41 call 2 */
        return 0;
    case 10499: /* module 41 call 3 */
        return 2;
    case 10500: /* module 41 call 4 */
        return 2;
    case 10501: /* module 41 call 5 */
        return 2;
    case 10502: /* module 41 call 6 */
        return 4;
    case 10503: /* module 41 call 7 */
        return 5;
    case 10504: /* module 41 call 8 */
        return 2;
    case 10505: /* module 41 call 9 */
        return 2;
    case 10506: /* module 41 call 10 */
        return 2;
    case 10507: /* module 41 call 11 */
        return 6;
    case 10508: /* module 41 call 12 */
        return 4;
    case 10509: /* module 41 call 13 */
        return 1;
    case 10510: /* module 41 call 14 */
        return 2;
    case 10511: /* module 41 call 15 */
        return 1;
    case 10512: /* module 41 call 16 */
        return 1;
    case 10513: /* module 41 call 17 */
        return 2;
    case 10514: /* module 41 call 18 */
        return 2;
    case 10515: /* module 41 call 19 */
        return 2;
    case 10516: /* module 41 call 20 */
        return 1;
    case 10752: /* module 42 call 0 */
        return 0;
    case 10753: /* module 42 call 1 */
        return 0;
    case 10754: /* module 42 call 2 */
        return 1;
    case 13056: /* module 51 call 0 */
        return 1;
    case 13057: /* module 51 call 1 */
        return 1;
    case 13058: /* module 51 call 2 */
        return 1;
    case 13059: /* module 51 call 3 */
        return 1;
    case 13060: /* module 51 call 4 */
        return 1;
    case 13061: /* module 51 call 5 */
        return 1;
    case 13062: /* module 51 call 6 */
        return 1;
    case 13063: /* module 51 call 7 */
        return 1;
    case 13064: /* module 51 call 8 */
        return 1;
    case 13065: /* module 51 call 9 */
        return 1;
    case 13066: /* module 51 call 10 */
        return 1;
    case 13067: /* module 51 call 11 */
        return 1;
    case 13068: /* module 51 call 12 */
        return 1;
    case 13069: /* module 51 call 13 */
        return 1;
    case 13070: /* module 51 call 14 */
        return 1;
    case 13071: /* module 51 call 15 */
        return 1;
    case 13074: /* module 51 call 18 */
        return 1;
    case 13075: /* module 51 call 19 */
        return 1;
    case 13076: /* module 51 call 20 */
        return 1;
    case 13077: /* module 51 call 21 */
        return 1;
    case 13078: /* module 51 call 22 */
        return 1;
    case 13079: /* module 51 call 23 */
        return 1;
    case 13080: /* module 51 call 24 */
        return 1;
    case 13081: /* module 51 call 25 */
        return 1;
    case 13082: /* module 51 call 26 */
        return 1;
    case 13083: /* module 51 call 27 */
        return 1;
    case 13084: /* module 51 call 28 */
        return 1;
    case 13085: /* module 51 call 29 */
        return 1;
    case 13086: /* module 51 call 30 */
        return 1;
    case 13087: /* module 51 call 31 */
        return 1;
    case 13088: /* module 51 call 32 */
        return 1;
    case 13089: /* module 51 call 33 */
        return 1;
    case 13090: /* module 51 call 34 */
        return 1;
    case 13091: /* module 51 call 35 */
        return 1;
    case 13092: /* module 51 call 36 */
        return 1;
    case 13093: /* module 51 call 37 */
        return 1;
    case 13094: /* module 51 call 38 */
        return 1;
    case 13095: /* module 51 call 39 */
        return 1;
    case 13096: /* module 51 call 40 */
        return 1;
    case 13097: /* module 51 call 41 */
        return 1;
    case 13098: /* module 51 call 42 */
        return 1;
    case 13099: /* module 51 call 43 */
        return 1;
    case 13100: /* module 51 call 44 */
        return 1;
    case 14592: /* module 57 call 0 */
        return 1;
    case 15104: /* module 59 call 0 */
        return 2;
    case 15872: /* module 62 call 0 */
        return 0;
    case 18432: /* module 72 call 0 */
        return 2;
    case 18433: /* module 72 call 1 */
        return 5;
    case 18434: /* module 72 call 2 */
        return 0;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V22(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 1031: /* module 4 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_signature;
        default:
            return NULL;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_memo;
        default:
            return NULL;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18696: /* module 73 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_signature;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        default:
            return NULL;
        }
    case 25346: /* module 99 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        default:
            return NULL;
        }
    case 25352: /* module 99 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 25353: /* module 99 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_old_reserved;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1030: /* module 4 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1032: /* module 4 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_nominator_bond;
        case 1:
            return STR_IT_min_validator_bond;
        case 2:
            return STR_IT_max_nominator_count;
        case 3:
            return STR_IT_max_validator_count;
        case 4:
            return STR_IT_chill_threshold;
        case 5:
            return STR_IT_min_commission;
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_to;
        case 2:
            return STR_IT_conviction;
        case 3:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_class_;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_track;
        default:
            return NULL;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_maybe_hash;
        default:
            return NULL;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_min_rank;
        default:
            return NULL;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll;
        case 1:
            return STR_IT_aye;
        default:
            return NULL;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll_index;
        case 1:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_track;
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_maybe_hash;
        default:
            return NULL;
        }
    case 11264: /* module 44 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 11265: /* module 44 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 11266: /* module 44 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call_hash;
        case 1:
            return STR_IT_call_encoded_len;
        case 2:
            return STR_IT_call_weight_witness;
        default:
            return NULL;
        }
    case 11267: /* module 44 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_old;
        case 1:
            return STR_IT_new_;
        case 2:
            return STR_IT_maybe_preclaim;
        default:
            return NULL;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_subs;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        case 3:
            return STR_IT_identity;
        default:
            return NULL;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6411: /* module 25 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 6412: /* module 25 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 6414: /* module 25 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pos;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_tip;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pos;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate;
        case 1:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_founder;
        case 1:
            return STR_IT_max_members;
        case 2:
            return STR_IT_rules;
        default:
            return NULL;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_forgive;
        default:
            return NULL;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        case 2:
            return STR_IT_curator;
        case 3:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        case 2:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_maybe_proportion;
        default:
            return NULL;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 9734: /* module 38 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_old_reserved;
        default:
            return NULL;
        }
    case 11522: /* module 45 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 11523: /* module 45 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 11524: /* module 45 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 11525: /* module 45 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 11526: /* module 45 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 11527: /* module 45 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 11528: /* module 45 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        default:
            return NULL;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dislocated;
        default:
            return NULL;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lighter;
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_extra;
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member_account;
        case 1:
            return STR_IT_unbonding_points;
        default:
            return NULL;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member_account;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_root;
        case 2:
            return STR_IT_nominator;
        case 3:
            return STR_IT_bouncer;
        default:
            return NULL;
        }
    case 10503: /* module 41 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_root;
        case 2:
            return STR_IT_nominator;
        case 3:
            return STR_IT_bouncer;
        case 4:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 10504: /* module 41 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 10505: /* module 41 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_state;
        default:
            return NULL;
        }
    case 10506: /* module 41 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_metadata;
        default:
            return NULL;
        }
    case 10507: /* module 41 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_join_bond;
        case 1:
            return STR_IT_min_create_bond;
        case 2:
            return STR_IT_max_pools;
        case 3:
            return STR_IT_max_members;
        case 4:
            return STR_IT_max_members_per_pool;
        case 5:
            return STR_IT_global_max_commission;
        default:
            return NULL;
        }
    case 10508: /* module 41 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_new_root;
        case 2:
            return STR_IT_new_nominator;
        case 3:
            return STR_IT_new_bouncer;
        default:
            return NULL;
        }
    case 10509: /* module 41 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 10510: /* module 41 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member;
        case 1:
            return STR_IT_extra;
        default:
            return NULL;
        }
    case 10511: /* module 41 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_permission;
        default:
            return NULL;
        }
    case 10512: /* module 41 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other;
        default:
            return NULL;
        }
    case 10513: /* module 41 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_new_commission;
        default:
            return NULL;
        }
    case 10514: /* module 41 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_max_commission;
        default:
            return NULL;
        }
    case 10515: /* module 41 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_change_rate;
        default:
            return NULL;
        }
    case 10516: /* module 41 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_eras_to_check;
        default:
            return NULL;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13082: /* module 51 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13091: /* module 51 call 35 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13094: /* module 51 call 38 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13096: /* module 51 call 40 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13097: /* module 51 call 41 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_up_to;
        default:
            return NULL;
        }
    case 15104: /* module 59 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_duration;
        case 1:
            return STR_IT_lease_period_index;
        default:
            return NULL;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_auction_index;
        case 2:
            return STR_IT_first_slot;
        case 3:
            return STR_IT_last_slot;
        case 4:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V22(
    pd_Method_V22_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_allow_death_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_allow_death_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_allow_death_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_allow_death_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V22 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V22.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_transfer_all_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V22 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V22.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1031: /* module 4 call 7 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V22 - controller */;
            return _toStringAccountIdLookupOfT(
                &m->nested.staking_bond_V22.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V22 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_bond_V22.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_extra_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_unbond_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V22 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_withdraw_unbonded_V22.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V22 - prefs */;
            return _toStringValidatorPrefs(
                &m->basic.staking_validate_V22.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V22 - targets */;
            return _toStringVecAccountIdLookupOfT(
                &m->nested.staking_nominate_V22.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V22 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_set_payee_V22.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V22 - controller */;
            return _toStringAccountIdLookupOfT(
                &m->nested.staking_set_controller_V22.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V22 - validator_stash */;
            return _toStringAccountId(
                &m->basic.staking_payout_stakers_V22.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V22 - era */;
            return _toStringEraIndex(
                &m->basic.staking_payout_stakers_V22.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_rebond_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V22 - keys */;
            return _toStringKeys(
                &m->basic.session_set_keys_V22.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V22 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V22.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V22 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V22.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V22 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V22.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V22 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V22.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0: /* crowdloan_create_V22 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_create_V22 - cap */;
            return _toStringCompactu128(
                &m->basic.crowdloan_create_V22.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_create_V22 - first_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V22.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_create_V22 - last_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V22.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_create_V22 - end */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V22.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_create_V22 - verifier */;
            return _toStringOptionMultiSigner(
                &m->basic.crowdloan_create_V22.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0: /* crowdloan_contribute_V22 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_contribute_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_contribute_V22 - amount */;
            return _toStringCompactu128(
                &m->basic.crowdloan_contribute_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_contribute_V22 - signature */;
            return _toStringOptionMultiSignature(
                &m->basic.crowdloan_contribute_V22.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0: /* crowdloan_withdraw_V22 - who */;
            return _toStringAccountId(
                &m->basic.crowdloan_withdraw_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_withdraw_V22 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_withdraw_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0: /* crowdloan_refund_V22 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_refund_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloan_dissolve_V22 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_dissolve_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0: /* crowdloan_edit_V22 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_edit_V22 - cap */;
            return _toStringCompactu128(
                &m->basic.crowdloan_edit_V22.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_edit_V22 - first_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V22.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_edit_V22 - last_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V22.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_edit_V22 - end */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V22.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_edit_V22 - verifier */;
            return _toStringOptionMultiSigner(
                &m->basic.crowdloan_edit_V22.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0: /* crowdloan_add_memo_V22 - index */;
            return _toStringParaId(
                &m->basic.crowdloan_add_memo_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_add_memo_V22 - memo */;
            return _toStringVecu8(
                &m->basic.crowdloan_add_memo_V22.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0: /* crowdloan_poke_V22 - index */;
            return _toStringParaId(
                &m->basic.crowdloan_poke_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18696: /* module 73 call 8 */
        switch (itemIdx) {
        case 0: /* crowdloan_contribute_all_V22 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_contribute_all_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_contribute_all_V22 - signature */;
            return _toStringOptionMultiSignature(
                &m->basic.crowdloan_contribute_all_V22.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        switch (itemIdx) {
        case 0: /* xcmpallet_teleport_assets_V22 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_teleport_assets_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_teleport_assets_V22 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_teleport_assets_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_teleport_assets_V22 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_teleport_assets_V22.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_teleport_assets_V22 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_teleport_assets_V22.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25346: /* module 99 call 2 */
        switch (itemIdx) {
        case 0: /* xcmpallet_reserve_transfer_assets_V22 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_reserve_transfer_assets_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_reserve_transfer_assets_V22 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_reserve_transfer_assets_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_reserve_transfer_assets_V22 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_reserve_transfer_assets_V22.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_reserve_transfer_assets_V22 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_reserve_transfer_assets_V22.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25352: /* module 99 call 8 */
        switch (itemIdx) {
        case 0: /* xcmpallet_limited_reserve_transfer_assets_V22 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_limited_reserve_transfer_assets_V22 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_limited_reserve_transfer_assets_V22 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V22.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_limited_reserve_transfer_assets_V22 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V22.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* xcmpallet_limited_reserve_transfer_assets_V22 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V22.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25353: /* module 99 call 9 */
        switch (itemIdx) {
        case 0: /* xcmpallet_limited_teleport_assets_V22 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_teleport_assets_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_limited_teleport_assets_V22 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_teleport_assets_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_limited_teleport_assets_V22 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_limited_teleport_assets_V22.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_limited_teleport_assets_V22 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_limited_teleport_assets_V22.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* xcmpallet_limited_teleport_assets_V22 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xcmpallet_limited_teleport_assets_V22.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V22 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V22.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V22 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V22.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V22 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V22.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V22 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V22.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V22 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V22.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V22 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V22.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V22 - index */;
            return _toStringAccountIndex(
                &m->basic.indices_claim_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V22 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.indices_transfer_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V22 - index */;
            return _toStringAccountIndex(
                &m->basic.indices_transfer_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V22 - index */;
            return _toStringAccountIndex(
                &m->basic.indices_free_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V22 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.indices_force_transfer_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V22 - index */;
            return _toStringAccountIndex(
                &m->basic.indices_force_transfer_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V22 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V22.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V22 - index */;
            return _toStringAccountIndex(
                &m->basic.indices_freeze_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_deprecated_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_set_balance_deprecated_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_deprecated_V22 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V22.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_deprecated_V22 - old_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V22.old_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V22 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1030: /* module 4 call 6 */
        switch (itemIdx) {
        case 0: /* balances_upgrade_accounts_V22 - who */;
            return _toStringVecAccountId(
                &m->basic.balances_upgrade_accounts_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1032: /* module 4 call 8 */
        switch (itemIdx) {
        case 0: /* balances_force_set_balance_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_set_balance_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_set_balance_V22 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_force_set_balance_V22.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V22 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V22 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V22.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V22 - factor */;
            return _toStringPercent(
                &m->basic.staking_scale_validator_count_V22.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V22 - invulnerables */;
            return _toStringVecAccountId(
                &m->basic.staking_set_invulnerables_V22.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V22 - stash */;
            return _toStringAccountId(
                &m->basic.staking_force_unstake_V22.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V22 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V22.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V22 - era */;
            return _toStringEraIndex(
                &m->basic.staking_cancel_deferred_slash_V22.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V22 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V22.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V22 - stash */;
            return _toStringAccountId(
                &m->basic.staking_reap_stash_V22.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V22 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V22.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* staking_kick_V22 - who */;
            return _toStringVecAccountIdLookupOfT(
                &m->basic.staking_kick_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* staking_set_staking_configs_V22 - min_nominator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.staking_set_staking_configs_V22.min_nominator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_staking_configs_V22 - min_validator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.staking_set_staking_configs_V22.min_validator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_set_staking_configs_V22 - max_nominator_count */;
            return _toStringConfigOpu32(
                &m->basic.staking_set_staking_configs_V22.max_nominator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_set_staking_configs_V22 - max_validator_count */;
            return _toStringConfigOpu32(
                &m->basic.staking_set_staking_configs_V22.max_validator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_set_staking_configs_V22 - chill_threshold */;
            return _toStringConfigOpPercent(
                &m->basic.staking_set_staking_configs_V22.chill_threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* staking_set_staking_configs_V22 - min_commission */;
            return _toStringConfigOpPerbill(
                &m->basic.staking_set_staking_configs_V22.min_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V22 - controller */;
            return _toStringAccountId(
                &m->basic.staking_chill_other_V22.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V22 - validator_stash */;
            return _toStringAccountId(
                &m->basic.staking_force_apply_min_commission_V22.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_min_commission_V22 - new_ */;
            return _toStringPerbill(
                &m->basic.staking_set_min_commission_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V22 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V22 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.treasury_propose_spend_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V22 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V22.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V22 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V22.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_spend_V22 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_spend_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_spend_V22 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.treasury_spend_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* treasury_remove_approval_V22 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_remove_approval_V22.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0: /* convictionvoting_vote_V22 - poll_index */;
            return _toStringCompactu32(
                &m->basic.convictionvoting_vote_V22.poll_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_vote_V22 - vote */;
            return _toStringAccountVote(
                &m->basic.convictionvoting_vote_V22.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0: /* convictionvoting_delegate_V22 - class_ */;
            return _toStringClassOf(
                &m->basic.convictionvoting_delegate_V22.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_delegate_V22 - to */;
            return _toStringAccountIdLookupOfT(
                &m->basic.convictionvoting_delegate_V22.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* convictionvoting_delegate_V22 - conviction */;
            return _toStringConviction(
                &m->basic.convictionvoting_delegate_V22.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* convictionvoting_delegate_V22 - balance */;
            return _toStringBalanceOf(
                &m->basic.convictionvoting_delegate_V22.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* convictionvoting_undelegate_V22 - class_ */;
            return _toStringClassOf(
                &m->basic.convictionvoting_undelegate_V22.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* convictionvoting_unlock_V22 - class_ */;
            return _toStringClassOf(
                &m->basic.convictionvoting_unlock_V22.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_unlock_V22 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.convictionvoting_unlock_V22.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* convictionvoting_remove_vote_V22 - class_ */;
            return _toStringOptionClassOf(
                &m->basic.convictionvoting_remove_vote_V22.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_remove_vote_V22 - index */;
            return _toStringPollIndexOf(
                &m->basic.convictionvoting_remove_vote_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0: /* convictionvoting_remove_other_vote_V22 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.convictionvoting_remove_other_vote_V22.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_remove_other_vote_V22 - class_ */;
            return _toStringClassOf(
                &m->basic.convictionvoting_remove_other_vote_V22.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* convictionvoting_remove_other_vote_V22 - index */;
            return _toStringPollIndexOf(
                &m->basic.convictionvoting_remove_other_vote_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* referenda_place_decision_deposit_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_place_decision_deposit_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* referenda_refund_decision_deposit_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_refund_decision_deposit_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0: /* referenda_cancel_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_cancel_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0: /* referenda_kill_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_kill_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0: /* referenda_nudge_referendum_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_nudge_referendum_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0: /* referenda_one_fewer_deciding_V22 - track */;
            return _toStringTrackIdOf(
                &m->basic.referenda_one_fewer_deciding_V22.track,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0: /* referenda_refund_submission_deposit_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_refund_submission_deposit_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0: /* referenda_set_metadata_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_set_metadata_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* referenda_set_metadata_V22 - maybe_hash */;
            return _toStringOptionPreimageHash(
                &m->basic.referenda_set_metadata_V22.maybe_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_add_member_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.fellowshipcollective_add_member_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_promote_member_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.fellowshipcollective_promote_member_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_demote_member_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.fellowshipcollective_demote_member_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_remove_member_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.fellowshipcollective_remove_member_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* fellowshipcollective_remove_member_V22 - min_rank */;
            return _toStringRank(
                &m->basic.fellowshipcollective_remove_member_V22.min_rank,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_vote_V22 - poll */;
            return _toStringPollIndexOf(
                &m->basic.fellowshipcollective_vote_V22.poll,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* fellowshipcollective_vote_V22 - aye */;
            return _toStringbool(
                &m->basic.fellowshipcollective_vote_V22.aye,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_cleanup_poll_V22 - poll_index */;
            return _toStringPollIndexOf(
                &m->basic.fellowshipcollective_cleanup_poll_V22.poll_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* fellowshipcollective_cleanup_poll_V22 - max */;
            return _toStringu32(
                &m->basic.fellowshipcollective_cleanup_poll_V22.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_place_decision_deposit_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.fellowshipreferenda_place_decision_deposit_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_refund_decision_deposit_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.fellowshipreferenda_refund_decision_deposit_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_cancel_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.fellowshipreferenda_cancel_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_kill_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.fellowshipreferenda_kill_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_nudge_referendum_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.fellowshipreferenda_nudge_referendum_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_one_fewer_deciding_V22 - track */;
            return _toStringTrackIdOf(
                &m->basic.fellowshipreferenda_one_fewer_deciding_V22.track,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_refund_submission_deposit_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.fellowshipreferenda_refund_submission_deposit_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_set_metadata_V22 - index */;
            return _toStringReferendumIndex(
                &m->basic.fellowshipreferenda_set_metadata_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* fellowshipreferenda_set_metadata_V22 - maybe_hash */;
            return _toStringOptionPreimageHash(
                &m->basic.fellowshipreferenda_set_metadata_V22.maybe_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11264: /* module 44 call 0 */
        switch (itemIdx) {
        case 0: /* whitelist_whitelist_call_V22 - call_hash */;
            return _toStringPreimageHash(
                &m->basic.whitelist_whitelist_call_V22.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11265: /* module 44 call 1 */
        switch (itemIdx) {
        case 0: /* whitelist_remove_whitelisted_call_V22 - call_hash */;
            return _toStringPreimageHash(
                &m->basic.whitelist_remove_whitelisted_call_V22.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11266: /* module 44 call 2 */
        switch (itemIdx) {
        case 0: /* whitelist_dispatch_whitelisted_call_V22 - call_hash */;
            return _toStringPreimageHash(
                &m->basic.whitelist_dispatch_whitelisted_call_V22.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* whitelist_dispatch_whitelisted_call_V22 - call_encoded_len */;
            return _toStringu32(
                &m->basic.whitelist_dispatch_whitelisted_call_V22.call_encoded_len,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* whitelist_dispatch_whitelisted_call_V22 - call_weight_witness */;
            return _toStringWeight(
                &m->basic.whitelist_dispatch_whitelisted_call_V22.call_weight_witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11267: /* module 44 call 3 */
        switch (itemIdx) {
        case 0: /* whitelist_dispatch_whitelisted_call_with_preimage_V22 - call */;
            return _toStringCall(
                &m->basic.whitelist_dispatch_whitelisted_call_with_preimage_V22.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* claims_claim_V22 - dest */;
            return _toStringAccountId(
                &m->basic.claims_claim_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_V22 - ethereum_signature */;
            return _toStringEcdsaSignature(
                &m->basic.claims_claim_V22.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* claims_claim_attest_V22 - dest */;
            return _toStringAccountId(
                &m->basic.claims_claim_attest_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_attest_V22 - ethereum_signature */;
            return _toStringEcdsaSignature(
                &m->basic.claims_claim_attest_V22.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_claim_attest_V22 - statement */;
            return _toStringBytes(
                &m->basic.claims_claim_attest_V22.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* claims_attest_V22 - statement */;
            return _toStringBytes(
                &m->basic.claims_attest_V22.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* claims_move_claim_V22 - old */;
            return _toStringEthereumAddress(
                &m->basic.claims_move_claim_V22.old,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_move_claim_V22 - new_ */;
            return _toStringEthereumAddress(
                &m->basic.claims_move_claim_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_move_claim_V22 - maybe_preclaim */;
            return _toStringOptionAccountId(
                &m->basic.claims_move_claim_V22.maybe_preclaim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V22 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V22.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V22 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V22.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V22 - account */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_add_registrar_V22.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V22 - info */;
            return _toStringIdentityInfo(
                &m->basic.identity_set_identity_V22.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V22 - subs */;
            return _toStringVecTupleAccountIdData(
                &m->basic.identity_set_subs_V22.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V22 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V22.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V22 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V22.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V22 - reg_index */;
            return _toStringRegistrarIndex(
                &m->basic.identity_cancel_request_V22.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V22 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V22 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V22.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V22 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V22 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_set_account_id_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6409: /* module 25 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V22 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_provide_judgement_V22.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V22 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_provide_judgement_V22.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V22 - judgement */;
            return _toStringJudgementBalanceOfT(
                &m->basic.identity_provide_judgement_V22.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* identity_provide_judgement_V22 - identity */;
            return _toStringHash(
                &m->basic.identity_provide_judgement_V22.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V22 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_kill_identity_V22.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6411: /* module 25 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V22 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_add_sub_V22.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V22 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V22.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6412: /* module 25 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V22 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_rename_sub_V22.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V22 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V22.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V22 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_remove_sub_V22.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6414: /* module 25 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* society_bid_V22 - amount */;
            return _toStringBalanceOf(
                &m->basic.society_bid_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* society_unbid_V22 - pos */;
            return _toStringu32(
                &m->basic.society_unbid_V22.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* society_vouch_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.society_vouch_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vouch_V22 - amount */;
            return _toStringBalanceOf(
                &m->basic.society_vouch_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_vouch_V22 - tip */;
            return _toStringBalanceOf(
                &m->basic.society_vouch_V22.tip,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* society_unvouch_V22 - pos */;
            return _toStringu32(
                &m->basic.society_unvouch_V22.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* society_vote_V22 - candidate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.society_vote_V22.candidate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vote_V22 - approve */;
            return _toStringbool(
                &m->basic.society_vote_V22.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* society_defender_vote_V22 - approve */;
            return _toStringbool(
                &m->basic.society_defender_vote_V22.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0: /* society_found_V22 - founder */;
            return _toStringAccountIdLookupOfT(
                &m->basic.society_found_V22.founder,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_found_V22 - max_members */;
            return _toStringu32(
                &m->basic.society_found_V22.max_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_found_V22 - rules */;
            return _toStringBytes(
                &m->basic.society_found_V22.rules,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0: /* society_judge_suspended_member_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.society_judge_suspended_member_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_judge_suspended_member_V22 - forgive */;
            return _toStringbool(
                &m->basic.society_judge_suspended_member_V22.forgive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0: /* society_set_max_members_V22 - max */;
            return _toStringu32(
                &m->basic.society_set_max_members_V22.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* recovery_set_recovered_V22 - lost */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_set_recovered_V22.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_set_recovered_V22 - rescuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_set_recovered_V22.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V22 - account */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_initiate_recovery_V22.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V22 - lost */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_vouch_recovery_V22.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V22 - rescuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_vouch_recovery_V22.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V22 - account */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_claim_recovery_V22.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V22 - rescuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_close_recovery_V22.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V22 - account */;
            return _toStringAccountIdLookupOfT(
                &m->basic.recovery_cancel_recovered_V22.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V22 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vest_other_V22.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V22 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vested_transfer_V22.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V22 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_vested_transfer_V22.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V22 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V22.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V22 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V22.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V22 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_force_vested_transfer_V22.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V22 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V22.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V22 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V22.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V22 - real */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_proxy_V22.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V22 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->nested.proxy_proxy_V22.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V22 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V22.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V22 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_add_proxy_V22.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V22 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_add_proxy_V22.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V22 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_add_proxy_V22.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V22 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_remove_proxy_V22.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V22 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_remove_proxy_V22.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V22 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_remove_proxy_V22.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_create_pure_V22 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_create_pure_V22.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_create_pure_V22 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_create_pure_V22.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_create_pure_V22 - index */;
            return _toStringu16(
                &m->nested.proxy_create_pure_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_pure_V22 - spawner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_kill_pure_V22.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_pure_V22 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_kill_pure_V22.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_pure_V22 - index */;
            return _toStringu16(
                &m->nested.proxy_kill_pure_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_pure_V22 - height */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V22.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_pure_V22 - ext_index */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V22.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V22 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V22.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V22 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V22.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V22 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->basic.proxy_proxy_announced_V22.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V22 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V22.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V22 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V22.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V22 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V22.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V22 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V22.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V22 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V22.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V22 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V22.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V22 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V22.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V22 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V22.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V22 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V22.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V22 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V22.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V22 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V22.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V22 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V22.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V22 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V22.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V22 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V22.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V22 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V22.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V22 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V22.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V22 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V22.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V22 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V22.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V22 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V22.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V22 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V22.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V22 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V22.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V22 - amount */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_bounty_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V22 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V22.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_approve_bounty_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_propose_curator_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V22 - curator */;
            return _toStringAccountIdLookupOfT(
                &m->basic.bounties_propose_curator_V22.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V22 - fee */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_curator_V22.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_unassign_curator_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_accept_curator_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_award_bounty_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V22 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.bounties_award_bounty_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_claim_bounty_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_close_bounty_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V22 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_extend_bounty_expiry_V22.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V22 - remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V22.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* childbounties_add_child_bounty_V22 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_add_child_bounty_V22.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_add_child_bounty_V22 - amount */;
            return _toStringCompactBalance(
                &m->basic.childbounties_add_child_bounty_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_add_child_bounty_V22 - description */;
            return _toStringVecu8(
                &m->basic.childbounties_add_child_bounty_V22.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* childbounties_propose_curator_V22 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_propose_curator_V22.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_propose_curator_V22 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_propose_curator_V22.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_propose_curator_V22 - curator */;
            return _toStringAccountIdLookupOfT(
                &m->basic.childbounties_propose_curator_V22.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* childbounties_propose_curator_V22 - fee */;
            return _toStringCompactBalance(
                &m->basic.childbounties_propose_curator_V22.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* childbounties_accept_curator_V22 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_accept_curator_V22.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_accept_curator_V22 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_accept_curator_V22.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        case 0: /* childbounties_unassign_curator_V22 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_unassign_curator_V22.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_unassign_curator_V22 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_unassign_curator_V22.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0: /* childbounties_award_child_bounty_V22 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_award_child_bounty_V22.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_award_child_bounty_V22 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_award_child_bounty_V22.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_award_child_bounty_V22 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.childbounties_award_child_bounty_V22.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0: /* childbounties_claim_child_bounty_V22 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_claim_child_bounty_V22.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_claim_child_bounty_V22 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_claim_child_bounty_V22.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0: /* childbounties_close_child_bounty_V22 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_close_child_bounty_V22.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_close_child_bounty_V22 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_close_child_bounty_V22.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* nis_place_bid_V22 - amount */;
            return _toStringCompactu128(
                &m->basic.nis_place_bid_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nis_place_bid_V22 - duration */;
            return _toStringu32(
                &m->basic.nis_place_bid_V22.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* nis_retract_bid_V22 - amount */;
            return _toStringCompactu128(
                &m->basic.nis_retract_bid_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nis_retract_bid_V22 - duration */;
            return _toStringu32(
                &m->basic.nis_retract_bid_V22.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* nis_thaw_private_V22 - index */;
            return _toStringCompactu32(
                &m->basic.nis_thaw_private_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nis_thaw_private_V22 - maybe_proportion */;
            return _toStringOptionPerquintill(
                &m->basic.nis_thaw_private_V22.maybe_proportion,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0: /* nis_thaw_communal_V22 - index */;
            return _toStringCompactu32(
                &m->basic.nis_thaw_communal_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0: /* nis_communify_V22 - index */;
            return _toStringCompactu32(
                &m->basic.nis_communify_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9734: /* module 38 call 6 */
        switch (itemIdx) {
        case 0: /* nis_privatize_V22 - index */;
            return _toStringCompactu32(
                &m->basic.nis_privatize_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_transfer_allow_death_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_transfer_allow_death_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_transfer_allow_death_V22 - amount */;
            return _toStringCompactu128(
                &m->basic.niscounterpartbalances_transfer_allow_death_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_set_balance_deprecated_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_set_balance_deprecated_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_set_balance_deprecated_V22 - new_free */;
            return _toStringCompactu128(
                &m->basic.niscounterpartbalances_set_balance_deprecated_V22.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* niscounterpartbalances_set_balance_deprecated_V22 - old_reserved */;
            return _toStringCompactu128(
                &m->basic.niscounterpartbalances_set_balance_deprecated_V22.old_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11522: /* module 45 call 2 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_force_transfer_V22 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_force_transfer_V22.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_force_transfer_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_force_transfer_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* niscounterpartbalances_force_transfer_V22 - amount */;
            return _toStringCompactu128(
                &m->basic.niscounterpartbalances_force_transfer_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11523: /* module 45 call 3 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_transfer_keep_alive_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_transfer_keep_alive_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_transfer_keep_alive_V22 - amount */;
            return _toStringCompactu128(
                &m->basic.niscounterpartbalances_transfer_keep_alive_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11524: /* module 45 call 4 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_transfer_all_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_transfer_all_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_transfer_all_V22 - keep_alive */;
            return _toStringbool(
                &m->basic.niscounterpartbalances_transfer_all_V22.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11525: /* module 45 call 5 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_force_unreserve_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_force_unreserve_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_force_unreserve_V22 - amount */;
            return _toStringBalance(
                &m->basic.niscounterpartbalances_force_unreserve_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11526: /* module 45 call 6 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_upgrade_accounts_V22 - who */;
            return _toStringVecAccountId(
                &m->basic.niscounterpartbalances_upgrade_accounts_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11527: /* module 45 call 7 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_transfer_V22 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_transfer_V22.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_transfer_V22 - amount */;
            return _toStringCompactu128(
                &m->basic.niscounterpartbalances_transfer_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11528: /* module 45 call 8 */
        switch (itemIdx) {
        case 0: /* niscounterpartbalances_force_set_balance_V22 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.niscounterpartbalances_force_set_balance_V22.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* niscounterpartbalances_force_set_balance_V22 - new_free */;
            return _toStringCompactu128(
                &m->basic.niscounterpartbalances_force_set_balance_V22.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0: /* voterlist_rebag_V22 - dislocated */;
            return _toStringAccountIdLookupOfT(
                &m->basic.voterlist_rebag_V22.dislocated,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0: /* voterlist_put_in_front_of_V22 - lighter */;
            return _toStringAccountIdLookupOfT(
                &m->basic.voterlist_put_in_front_of_V22.lighter,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* nominationpools_join_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.nominationpools_join_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_join_V22 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_join_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* nominationpools_bond_extra_V22 - extra */;
            return _toStringBondExtraBalanceOfT(
                &m->nested.nominationpools_bond_extra_V22.extra,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* nominationpools_unbond_V22 - member_account */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_unbond_V22.member_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_unbond_V22 - unbonding_points */;
            return _toStringCompactBalance(
                &m->nested.nominationpools_unbond_V22.unbonding_points,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0: /* nominationpools_pool_withdraw_unbonded_V22 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_pool_withdraw_unbonded_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_pool_withdraw_unbonded_V22 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.nominationpools_pool_withdraw_unbonded_V22.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        case 0: /* nominationpools_withdraw_unbonded_V22 - member_account */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_withdraw_unbonded_V22.member_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_withdraw_unbonded_V22 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.nominationpools_withdraw_unbonded_V22.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        case 0: /* nominationpools_create_V22 - amount */;
            return _toStringCompactBalance(
                &m->nested.nominationpools_create_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_create_V22 - root */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_create_V22.root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_create_V22 - nominator */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_create_V22.nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_create_V22 - bouncer */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_create_V22.bouncer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10503: /* module 41 call 7 */
        switch (itemIdx) {
        case 0: /* nominationpools_create_with_pool_id_V22 - amount */;
            return _toStringCompactBalance(
                &m->basic.nominationpools_create_with_pool_id_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_create_with_pool_id_V22 - root */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_create_with_pool_id_V22.root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_create_with_pool_id_V22 - nominator */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_create_with_pool_id_V22.nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_create_with_pool_id_V22 - bouncer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_create_with_pool_id_V22.bouncer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nominationpools_create_with_pool_id_V22 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_create_with_pool_id_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10504: /* module 41 call 8 */
        switch (itemIdx) {
        case 0: /* nominationpools_nominate_V22 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_nominate_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_nominate_V22 - validators */;
            return _toStringVecAccountId(
                &m->nested.nominationpools_nominate_V22.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10505: /* module 41 call 9 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_state_V22 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_set_state_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_state_V22 - state */;
            return _toStringPoolState(
                &m->nested.nominationpools_set_state_V22.state,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10506: /* module 41 call 10 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_metadata_V22 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_set_metadata_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_metadata_V22 - metadata */;
            return _toStringVecu8(
                &m->nested.nominationpools_set_metadata_V22.metadata,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10507: /* module 41 call 11 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_configs_V22 - min_join_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.nominationpools_set_configs_V22.min_join_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_configs_V22 - min_create_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.nominationpools_set_configs_V22.min_create_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_set_configs_V22 - max_pools */;
            return _toStringConfigOpu32(
                &m->basic.nominationpools_set_configs_V22.max_pools,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_set_configs_V22 - max_members */;
            return _toStringConfigOpu32(
                &m->basic.nominationpools_set_configs_V22.max_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nominationpools_set_configs_V22 - max_members_per_pool */;
            return _toStringConfigOpu32(
                &m->basic.nominationpools_set_configs_V22.max_members_per_pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* nominationpools_set_configs_V22 - global_max_commission */;
            return _toStringConfigOpPerbill(
                &m->basic.nominationpools_set_configs_V22.global_max_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10508: /* module 41 call 12 */
        switch (itemIdx) {
        case 0: /* nominationpools_update_roles_V22 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_update_roles_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_update_roles_V22 - new_root */;
            return _toStringConfigOpAccountId(
                &m->nested.nominationpools_update_roles_V22.new_root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_update_roles_V22 - new_nominator */;
            return _toStringConfigOpAccountId(
                &m->nested.nominationpools_update_roles_V22.new_nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_update_roles_V22 - new_bouncer */;
            return _toStringConfigOpAccountId(
                &m->nested.nominationpools_update_roles_V22.new_bouncer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10509: /* module 41 call 13 */
        switch (itemIdx) {
        case 0: /* nominationpools_chill_V22 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_chill_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10510: /* module 41 call 14 */
        switch (itemIdx) {
        case 0: /* nominationpools_bond_extra_other_V22 - member */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_bond_extra_other_V22.member,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_bond_extra_other_V22 - extra */;
            return _toStringBondExtraBalanceOfT(
                &m->basic.nominationpools_bond_extra_other_V22.extra,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10511: /* module 41 call 15 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_claim_permission_V22 - permission */;
            return _toStringClaimPermission(
                &m->basic.nominationpools_set_claim_permission_V22.permission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10512: /* module 41 call 16 */
        switch (itemIdx) {
        case 0: /* nominationpools_claim_payout_other_V22 - other */;
            return _toStringAccountId(
                &m->basic.nominationpools_claim_payout_other_V22.other,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10513: /* module 41 call 17 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_commission_V22 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_set_commission_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_commission_V22 - new_commission */;
            return _toStringOptionTuplePerbillAccountId(
                &m->basic.nominationpools_set_commission_V22.new_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10514: /* module 41 call 18 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_commission_max_V22 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_set_commission_max_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_commission_max_V22 - max_commission */;
            return _toStringPerbill(
                &m->basic.nominationpools_set_commission_max_V22.max_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10515: /* module 41 call 19 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_commission_change_rate_V22 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_set_commission_change_rate_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_commission_change_rate_V22 - change_rate */;
            return _toStringCommissionChangeRateBlockNumber(
                &m->basic.nominationpools_set_commission_change_rate_V22.change_rate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10516: /* module 41 call 20 */
        switch (itemIdx) {
        case 0: /* nominationpools_claim_commission_V22 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_claim_commission_V22.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0: /* fastunstake_control_V22 - eras_to_check */;
            return _toStringEraIndex(
                &m->basic.fastunstake_control_V22.eras_to_check,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_cooldown_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_cooldown_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_delay_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_delay_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0: /* configuration_set_code_retention_period_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_code_retention_period_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_code_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_code_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_pov_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_pov_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_head_data_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_head_data_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0: /* configuration_set_parathread_cores_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_parathread_cores_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0: /* configuration_set_parathread_retries_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_parathread_retries_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0: /* configuration_set_group_rotation_frequency_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_group_rotation_frequency_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0: /* configuration_set_chain_availability_period_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_chain_availability_period_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0: /* configuration_set_thread_availability_period_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_thread_availability_period_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0: /* configuration_set_scheduling_lookahead_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_scheduling_lookahead_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_per_core_V22 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_per_core_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_V22 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_period_V22 - new_ */;
            return _toStringSessionIndex(
                &m->basic.configuration_set_dispute_period_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_post_conclusion_acceptance_period_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_dispute_post_conclusion_acceptance_period_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0: /* configuration_set_no_show_slots_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_no_show_slots_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0: /* configuration_set_n_delay_tranches_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_n_delay_tranches_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0: /* configuration_set_zeroth_delay_tranche_width_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_zeroth_delay_tranche_width_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0: /* configuration_set_needed_approvals_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_needed_approvals_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0: /* configuration_set_relay_vrf_modulo_samples_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_relay_vrf_modulo_samples_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_count_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_count_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_downward_message_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_downward_message_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13082: /* module 51 call 26 */
        switch (itemIdx) {
        case 0: /* configuration_set_ump_service_total_weight_V22 - new_ */;
            return _toStringWeight(
                &m->basic.configuration_set_ump_service_total_weight_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_num_per_candidate_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_num_per_candidate_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_open_request_ttl_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_open_request_ttl_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_sender_deposit_V22 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_sender_deposit_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_recipient_deposit_V22 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_recipient_deposit_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_capacity_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_capacity_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_total_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_total_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_inbound_channels_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_inbound_channels_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13091: /* module 51 call 35 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parathread_inbound_channels_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parathread_inbound_channels_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_message_size_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_message_size_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_outbound_channels_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_outbound_channels_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13094: /* module 51 call 38 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parathread_outbound_channels_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parathread_outbound_channels_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_message_num_per_candidate_V22 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_message_num_per_candidate_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13096: /* module 51 call 40 */
        switch (itemIdx) {
        case 0: /* configuration_set_ump_max_individual_weight_V22 - new_ */;
            return _toStringWeight(
                &m->basic.configuration_set_ump_max_individual_weight_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13097: /* module 51 call 41 */
        switch (itemIdx) {
        case 0: /* configuration_set_pvf_checking_enabled_V22 - new_ */;
            return _toStringbool(
                &m->basic.configuration_set_pvf_checking_enabled_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0: /* configuration_set_pvf_voting_ttl_V22 - new_ */;
            return _toStringSessionIndex(
                &m->basic.configuration_set_pvf_voting_ttl_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0: /* configuration_set_minimum_validation_upgrade_delay_V22 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_minimum_validation_upgrade_delay_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0: /* configuration_set_bypass_consistency_check_V22 - new_ */;
            return _toStringbool(
                &m->basic.configuration_set_bypass_consistency_check_V22.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0: /* initializer_force_approve_V22 - up_to */;
            return _toStringBlockNumber(
                &m->basic.initializer_force_approve_V22.up_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15104: /* module 59 call 0 */
        switch (itemIdx) {
        case 0: /* ump_service_overweight_V22 - index */;
            return _toStringOverweightIndex(
                &m->basic.ump_service_overweight_V22.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* ump_service_overweight_V22 - weight_limit */;
            return _toStringWeight(
                &m->basic.ump_service_overweight_V22.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0: /* auctions_new_auction_V22 - duration */;
            return _toStringCompactu32(
                &m->basic.auctions_new_auction_V22.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_new_auction_V22 - lease_period_index */;
            return _toStringCompactu32(
                &m->basic.auctions_new_auction_V22.lease_period_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0: /* auctions_bid_V22 - para */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V22.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_bid_V22 - auction_index */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V22.auction_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* auctions_bid_V22 - first_slot */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V22.first_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* auctions_bid_V22 - last_slot */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V22.last_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* auctions_bid_V22 - amount */;
            return _toStringCompactBalance(
                &m->basic.auctions_bid_V22.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V22(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1539: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1551: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1556: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 10500: // NominationPools:Pool withdraw unbonded
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 10501: // NominationPools:Withdraw Unbonded
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V22(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: // Timestamp:Set
    case 768: // Indices:Claim
    case 769: // Indices:Transfer
    case 770: // Indices:Free
    case 771: // Indices:Force transfer
    case 772: // Indices:Freeze
    case 1028: // Balances:Transfer all
    case 1029: // Balances:Force unreserve
    case 1030: // Balances:Upgrade accounts
    case 1032: // Balances:Force set balance
    case 1540: // Staking:Validate
    case 1545: // Staking:Set validator count
    case 1546: // Staking:Increase validator count
    case 1547: // Staking:Scale validator count
    case 1548: // Staking:Force no eras
    case 1549: // Staking:Force new era
    case 1550: // Staking:Set invulnerables
    case 1551: // Staking:Force unstake
    case 1552: // Staking:Force new era always
    case 1553: // Staking:Cancel deferred slash
    case 1554: // Staking:Payout stakers
    case 1556: // Staking:Reap stash
    case 1557: // Staking:Kick
    case 1558: // Staking:Set staking configs
    case 1559: // Staking:Chill other
    case 1560: // Staking:Force apply min commission
    case 1561: // Staking:Set min commission
    case 2048: // Session:Set keys
    case 2049: // Session:Purge keys
    case 4608: // Treasury:Propose spend
    case 4609: // Treasury:Reject proposal
    case 4610: // Treasury:Approve proposal
    case 4611: // Treasury:Spend
    case 4612: // Treasury:Remove approval
    case 5120: // ConvictionVoting:Vote
    case 5121: // ConvictionVoting:Delegate
    case 5122: // ConvictionVoting:Undelegate
    case 5123: // ConvictionVoting:Unlock
    case 5124: // ConvictionVoting:Remove vote
    case 5125: // ConvictionVoting:Remove other vote
    case 5377: // Referenda:Place decision deposit
    case 5378: // Referenda:Refund decision deposit
    case 5379: // Referenda:Cancel
    case 5380: // Referenda:Kill
    case 5381: // Referenda:Nudge referendum
    case 5382: // Referenda:One fewer deciding
    case 5383: // Referenda:Refund submission deposit
    case 5384: // Referenda:Set metadata
    case 5632: // FellowshipCollective:Add member
    case 5633: // FellowshipCollective:Promote member
    case 5634: // FellowshipCollective:Demote member
    case 5635: // FellowshipCollective:Remove member
    case 5636: // FellowshipCollective:Vote
    case 5637: // FellowshipCollective:Cleanup poll
    case 5889: // FellowshipReferenda:Place decision deposit
    case 5890: // FellowshipReferenda:Refund decision deposit
    case 5891: // FellowshipReferenda:Cancel
    case 5892: // FellowshipReferenda:Kill
    case 5893: // FellowshipReferenda:Nudge referendum
    case 5894: // FellowshipReferenda:One fewer deciding
    case 5895: // FellowshipReferenda:Refund submission deposit
    case 5896: // FellowshipReferenda:Set metadata
    case 11264: // Whitelist:Whitelist call
    case 11265: // Whitelist:Remove whitelisted call
    case 11266: // Whitelist:Dispatch whitelisted call
    case 11267: // Whitelist:Dispatch whitelisted call with preimage
    case 4864: // Claims:Claim
    case 4866: // Claims:Claim attest
    case 4867: // Claims:Attest
    case 4868: // Claims:Move claim
    case 6144: // Utility:Batch
    case 6146: // Utility:Batch all
    case 6148: // Utility:Force batch
    case 6149: // Utility:With weight
    case 6400: // Identity:Add registrar
    case 6401: // Identity:Set identity
    case 6402: // Identity:Set subs
    case 6403: // Identity:Clear identity
    case 6404: // Identity:Request judgement
    case 6405: // Identity:Cancel request
    case 6406: // Identity:Set fee
    case 6407: // Identity:Set account id
    case 6409: // Identity:Provide judgement
    case 6410: // Identity:Kill identity
    case 6411: // Identity:Add sub
    case 6412: // Identity:Rename sub
    case 6413: // Identity:Remove sub
    case 6414: // Identity:Quit sub
    case 6656: // Society:Bid
    case 6657: // Society:Unbid
    case 6658: // Society:Vouch
    case 6659: // Society:Unvouch
    case 6660: // Society:Vote
    case 6661: // Society:Defender vote
    case 6662: // Society:Payout
    case 6663: // Society:Found
    case 6664: // Society:Unfound
    case 6665: // Society:Judge suspended member
    case 6667: // Society:Set max members
    case 6913: // Recovery:Set recovered
    case 6915: // Recovery:Initiate recovery
    case 6916: // Recovery:Vouch recovery
    case 6917: // Recovery:Claim recovery
    case 6918: // Recovery:Close recovery
    case 6919: // Recovery:Remove recovery
    case 6920: // Recovery:Cancel recovered
    case 7168: // Vesting:Vest
    case 7169: // Vesting:Vest other
    case 7170: // Vesting:Vested transfer
    case 7171: // Vesting:Force vested transfer
    case 7172: // Vesting:Merge schedules
    case 7683: // Proxy:Remove proxies
    case 7689: // Proxy:Proxy announced
    case 8192: // Preimage:Note preimage
    case 8193: // Preimage:Unnote preimage
    case 8194: // Preimage:Request preimage
    case 8195: // Preimage:Unrequest preimage
    case 8960: // Bounties:Propose bounty
    case 8961: // Bounties:Approve bounty
    case 8962: // Bounties:Propose curator
    case 8963: // Bounties:Unassign curator
    case 8964: // Bounties:Accept curator
    case 8965: // Bounties:Award bounty
    case 8966: // Bounties:Claim bounty
    case 8967: // Bounties:Close bounty
    case 8968: // Bounties:Extend bounty expiry
    case 10240: // ChildBounties:Add child bounty
    case 10241: // ChildBounties:Propose curator
    case 10242: // ChildBounties:Accept curator
    case 10243: // ChildBounties:Unassign curator
    case 10244: // ChildBounties:Award child bounty
    case 10245: // ChildBounties:Claim child bounty
    case 10246: // ChildBounties:Close child bounty
    case 9728: // Nis:Place bid
    case 9729: // Nis:Retract bid
    case 9730: // Nis:Fund deficit
    case 9731: // Nis:Thaw private
    case 9732: // Nis:Thaw communal
    case 9733: // Nis:Communify
    case 9734: // Nis:Privatize
    case 11520: // NisCounterpartBalances:Transfer allow death
    case 11521: // NisCounterpartBalances:Set balance deprecated
    case 11522: // NisCounterpartBalances:Force transfer
    case 11523: // NisCounterpartBalances:Transfer keep alive
    case 11524: // NisCounterpartBalances:Transfer all
    case 11525: // NisCounterpartBalances:Force unreserve
    case 11526: // NisCounterpartBalances:Upgrade accounts
    case 11527: // NisCounterpartBalances:Transfer
    case 11528: // NisCounterpartBalances:Force set balance
    case 9984: // VoterList:Rebag
    case 9985: // VoterList:Put in front of
    case 10500: // NominationPools:Pool withdraw unbonded
    case 10503: // NominationPools:Create with pool id
    case 10507: // NominationPools:Set configs
    case 10510: // NominationPools:Bond extra other
    case 10511: // NominationPools:Set claim permission
    case 10512: // NominationPools:Claim payout other
    case 10513: // NominationPools:Set commission
    case 10514: // NominationPools:Set commission max
    case 10515: // NominationPools:Set commission change rate
    case 10516: // NominationPools:Claim commission
    case 10754: // FastUnstake:Control
    case 13056: // Configuration:Set validation upgrade cooldown
    case 13057: // Configuration:Set validation upgrade delay
    case 13058: // Configuration:Set code retention period
    case 13059: // Configuration:Set max code size
    case 13060: // Configuration:Set max pov size
    case 13061: // Configuration:Set max head data size
    case 13062: // Configuration:Set parathread cores
    case 13063: // Configuration:Set parathread retries
    case 13064: // Configuration:Set group rotation frequency
    case 13065: // Configuration:Set chain availability period
    case 13066: // Configuration:Set thread availability period
    case 13067: // Configuration:Set scheduling lookahead
    case 13068: // Configuration:Set max validators per core
    case 13069: // Configuration:Set max validators
    case 13070: // Configuration:Set dispute period
    case 13071: // Configuration:Set dispute post conclusion acceptance period
    case 13074: // Configuration:Set no show slots
    case 13075: // Configuration:Set n delay tranches
    case 13076: // Configuration:Set zeroth delay tranche width
    case 13077: // Configuration:Set needed approvals
    case 13078: // Configuration:Set relay vrf modulo samples
    case 13079: // Configuration:Set max upward queue count
    case 13080: // Configuration:Set max upward queue size
    case 13081: // Configuration:Set max downward message size
    case 13082: // Configuration:Set ump service total weight
    case 13083: // Configuration:Set max upward message size
    case 13084: // Configuration:Set max upward message num per candidate
    case 13085: // Configuration:Set hrmp open request ttl
    case 13086: // Configuration:Set hrmp sender deposit
    case 13087: // Configuration:Set hrmp recipient deposit
    case 13088: // Configuration:Set hrmp channel max capacity
    case 13089: // Configuration:Set hrmp channel max total size
    case 13090: // Configuration:Set hrmp max parachain inbound channels
    case 13091: // Configuration:Set hrmp max parathread inbound channels
    case 13092: // Configuration:Set hrmp channel max message size
    case 13093: // Configuration:Set hrmp max parachain outbound channels
    case 13094: // Configuration:Set hrmp max parathread outbound channels
    case 13095: // Configuration:Set hrmp max message num per candidate
    case 13096: // Configuration:Set ump max individual weight
    case 13097: // Configuration:Set pvf checking enabled
    case 13098: // Configuration:Set pvf voting ttl
    case 13099: // Configuration:Set minimum validation upgrade delay
    case 13100: // Configuration:Set bypass consistency check
    case 14592: // Initializer:Force approve
    case 15104: // Ump:Service overweight
    case 15872: // ParasDisputes:Force unfreeze
    case 18432: // Auctions:New auction
    case 18433: // Auctions:Bid
    case 18434: // Auctions:Cancel auction
    case 18688: // Crowdloan:Create
    case 18689: // Crowdloan:Contribute
    case 18690: // Crowdloan:Withdraw
    case 18691: // Crowdloan:Refund
    case 18692: // Crowdloan:Dissolve
    case 18693: // Crowdloan:Edit
    case 18694: // Crowdloan:Add memo
    case 18695: // Crowdloan:Poke
    case 18696: // Crowdloan:Contribute all
    case 25345: // XcmPallet:Teleport assets
    case 25346: // XcmPallet:Reserve transfer assets
    case 25352: // XcmPallet:Limited reserve transfer assets
    case 25353: // XcmPallet:Limited teleport assets
        return false;
    default:
        return true;
    }
}
