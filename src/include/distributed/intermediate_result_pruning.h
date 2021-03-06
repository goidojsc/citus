/*-------------------------------------------------------------------------
 *
 * intermediate_result_pruning.h
 *   Functions for pruning intermediate result broadcasting.
 *
 * Copyright (c) Citus Data, Inc.
 *
 *-------------------------------------------------------------------------
 */

#ifndef INTERMEDIATE_RESULT_PRUNING_H
#define INTERMEDIATE_RESULT_PRUNING_H

#include "distributed/subplan_execution.h"

/*
 * UINT32_MAX is reserved in pg_dist_node, so we can use it safely.
 */
#define LOCAL_NODE_ID UINT32_MAX

extern bool LogIntermediateResults;

extern List * FindSubPlansUsedInNode(Node *node);
extern List * FindAllWorkerNodesUsingSubplan(HTAB *intermediateResultsHash,
											 char *resultId);
extern HTAB * MakeIntermediateResultHTAB(void);
extern void RecordSubplanExecutionsOnNodes(HTAB *intermediateResultsHash,
										   DistributedPlan *distributedPlan);
extern IntermediateResultsHashEntry * SearchIntermediateResult(HTAB *resultsHash,
															   char *resultId);

/* utility functions related to UsedSubPlans */
extern List * MergeUsedSubPlanLists(List *leftSubPlanList, List *rightSubPlanList);
extern void UpdateUsedPlanListLocation(List *subPlanList, int localtionMask);

#endif /* INTERMEDIATE_RESULT_PRUNING_H */
