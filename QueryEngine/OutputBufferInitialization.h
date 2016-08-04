/**
 * @file    OutputBufferInitialization.h
 * @author  Alex Suhan <alex@mapd.com>
 */

#ifndef QUERYENGINE_OUTPUTBUFFERINITIALIZATION_H
#define QUERYENGINE_OUTPUTBUFFERINITIALIZATION_H

#include "SqlTypesLayout.h"

#include <list>
#include <memory>
#include <utility>
#include <vector>

namespace Analyzer {
class Expr;
}  // Analyzer

std::pair<int64_t, int64_t> inline_int_max_min(const size_t byte_width);

int64_t get_initial_val(const TargetInfo& target_info, const size_t min_byte_width_to_compact);

int64_t get_agg_initial_val(const SQLAgg agg,
                            const SQLTypeInfo& ti,
                            const bool enable_compaction,
                            const unsigned min_byte_width_to_compact);

std::vector<int64_t> init_agg_val_vec(const std::vector<Analyzer::Expr*>& targets,
                                      const std::list<std::shared_ptr<Analyzer::Expr>>& quals,
                                      size_t agg_col_count,
                                      const bool is_group_by,
                                      const size_t min_byte_width_to_compact,
                                      const bool input_is_empty);

const Analyzer::Expr* agg_arg(const Analyzer::Expr* expr);

bool constrained_not_null(const Analyzer::Expr* expr, const std::list<std::shared_ptr<Analyzer::Expr>>& quals);

#endif  // QUERYENGINE_OUTPUTBUFFERINITIALIZATION_H
